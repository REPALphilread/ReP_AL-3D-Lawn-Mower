#include "esp_camera.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

//
// WARNING!!! Make sure that you have either selected ESP32 Wrover Module,
//            or another board which has PSRAM enabled
//

// Select camera model
//#define CAMERA_MODEL_WROVER_KIT
//#define CAMERA_MODEL_ESP_EYE
//#define CAMERA_MODEL_M5STACK_PSRAM
//#define CAMERA_MODEL_M5STACK_WIDE
#define CAMERA_MODEL_AI_THINKER

#include "camera_pins.h"

//const char* ssid = "WLAN Name";
//const char* password = "WLAN Password";

const char* ssid = "WLAN Name";
const char* pass = "WLAN Password";

char auth[] = "Blynk Code";  // BLYNk Code for AITHINKER

#define LED_BUILTIN 4
BlynkTimer timer;


void startCameraServer();

int LED_loop;



void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  pinMode (LED_BUILTIN, OUTPUT);

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  //init with high specs to pre-allocate larger buffers
  if(psramFound()){
    config.frame_size = FRAMESIZE_UXGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }

#if defined(CAMERA_MODEL_ESP_EYE)
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
#endif

  // camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  sensor_t * s = esp_camera_sensor_get();
  //initial sensors are flipped vertically and colors are a bit saturated
  if (s->id.PID == OV3660_PID) {
    s->set_vflip(s, 1);//flip it back
    s->set_brightness(s, 1);//up the blightness just a bit
    s->set_saturation(s, -2);//lower the saturation
  }
  //drop down frame size for higher initial frame rate
  s->set_framesize(s, FRAMESIZE_VGA);

#if defined(CAMERA_MODEL_M5STACK_WIDE)
  s->set_vflip(s, 1);
  s->set_hmirror(s, 1);
#endif

//Delay 20seconds to give time for the GPS module to connect
Serial.println("Waiting 20 seconds");
delay(5000);
Serial.println("Waiting 15 seconds");
delay(5000);
Serial.println("Waiting 10 seconds");
delay(5000);
Serial.println("Waiting 5 seconds");
delay(5000);
Serial.println("Wait Over..");

Set_Mode_ESP32_WIFI();
WIFI_Connect();
startCameraServer();
}

void loop() {

  if(!Blynk.connected()) {
    Blynk.run();
    timer.run();  
    Serial.println("------------------------");
    Serial.println("ESPCAM Disconnected");
    Serial.println("Reconnecting ... ");
    Set_Mode_ESP32_WIFI ();Set_Mode_ESP32_WIFI ();
    Set_Mode_ESP32_WIFI ();
    WIFI_Connect() ;
    startCameraServer();
    }
  else {
    Blynk.run();
    timer.run();  
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("ESPCAM Running use http://");
    Serial.print(WiFi.localIP());
    Serial.println("");     // new line serial monitor
    if (LED_loop == 1) Blynk.virtualWrite(V1, 1023);
    if (LED_loop == 0) Blynk.virtualWrite(V1, 0);
    LED_loop = LED_loop + 1;
    if (LED_loop > 1) LED_loop = 0;
    
    
  }
delay(10000);

}





void WIFI_Connect() {
  
  // Flash LED on front of Camera
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  
  int connect_attempts = 0;
  int max_connect_attempts = 20;
  Serial.println();
  Serial.println("*********************************************");
  Serial.println("Connecting to WIFI");
  Serial.println(ssid);
  Serial.print("WIFI Connection Try:");
  
  while (!Blynk.connected())  {    //!= WL_CONNECTED
      delay(500);
      WiFi.begin(auth, ssid);
      Blynk.begin(auth, ssid, pass);
      connect_attempts = connect_attempts + 1;      
      Serial.print(".");
      if (!Blynk.connected()) {
        delay(2000);
        Set_Mode_ESP32_WIFI();
        }
      
      if (connect_attempts > max_connect_attempts) {
           ESP.restart();
           Serial.println("Restarting ESP");                     // try for less than 4 seconds to connect to WiFi router
           }
      }
  
  if(!Blynk.connected()) {
  //if (WiFi.status() != WL_CONNECTED) {
    Serial.println("ESPCAM didnt connect");
    Serial.println("Re-trying . . . . . . ");
    Set_Mode_ESP32_WIFI();
    WIFI_Connect();
    }
    
  else {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("ESPCAM Connected. . . . . .");
    // Setup a function to be called every second
    //startCameraServer();
    Serial.print("Camera Ready! Use 'http://");
    Serial.print(WiFi.localIP());
    Serial.println("' to connect");
    String LocalIP = String() + WiFi.localIP()[0] + "." + WiFi.localIP()[1] + "." + WiFi.localIP()[2] + "." +
    WiFi.localIP()[3];
    Blynk.virtualWrite(V2, LocalIP);
    }


}


void Set_Mode_ESP32_WIFI() {
  Serial.print("WIFI Status:");
  Serial.println(WiFi.getMode());
  WiFi.disconnect(true);
  delay(1000);
  WiFi.mode(WIFI_STA);
  delay(1000);
  Serial.print("WIFI Status:");
  Serial.println(WiFi.getMode());
  delay(2000);
  
}


void myTimerEvent()  {


}
