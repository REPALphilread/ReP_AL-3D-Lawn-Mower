

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h> // for MQTT
#include "config.h" //Config file for credentials

SoftwareSerial NodeMCU(D2,D3);   //RXD2 TXD3

//#define LED LED_BUILTIN

#define LED D4      // on various NODEMCU boards the LED Pin is different.....

#define pc(v) Serial.print("Ligne_") ; Serial.print(__LINE__) ; Serial.print(" ; ") ;Serial.print(#v) ;Serial.print(" = ") ; Serial.println((v)) ;

///////////***********MQTT*************////////
WiFiClient espClient;
PubSubClient client(espClient);
int Charge_old = 0;
int Tracking_old = 0;
int Mower_Parked_old = 0;
int Mower_Running_Filter_old = 0;
int Mower_Docked_Filter_old = 0;

///////////***********MQTT*************////////
int buttonState = 0;
char  Version[16];

// RX Variables
float val_VoltNow;                  // Battery Voltage from MEGA
float BatteryVoltage;               // Voltage read last RX
int Loop_Cycle_Mowing;              // Current Loop Cycle from MEGA

int Mower_Parked;
int Mower_Parked_Low_Batt;
int Mower_Docked;
int Mower_Docked_Filter;
int Mower_Running;
int Mower_Running_Filter;
int Mower_Lost;
int Charge_Detected;
int Tracking_Wire;
int Compass_Heading_Lock;

int i;                              // Transmit blank code

bool Mower_Already_Started = 0;
bool Going_Home_Already = 0;

int j;
int k;
int transmit_blynk_code = 0;

bool Manuel_Mode;
int Automatic_Mode;


int loopstatus = 0;
int All;
int RX_Data_Recieved;
int lastConnectionAttempt = millis();
int connectionDelay = 5000; // try to reconnect every 5 seconds

BlynkTimer timer;
WidgetLCD lcd(V6);


// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

void myTimerEvent()  {
  if (  (BatteryVoltage > 10) && (BatteryVoltage < 15) ){
      Blynk.virtualWrite(V3, BatteryVoltage);
  }

  Blynk.virtualWrite(V5, Loop_Cycle_Mowing);


}

void setup()
{

  //Serial.begin(9600);
  NodeMCU.begin(9600);
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println();
    Serial.println("debug mode on");
    Serial.println("Setting up NODEMCU........");
    Serial.println("");
  #endif
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  digitalWrite(LED, HIGH);                          // Turn off LED Light
  WIFI_Connect();                                   // Connect to the WIFI
  if (app == "Blynk") Clear_APP();
  lcd.clear();
  pinMode(LED, OUTPUT);


}



//Functions
//***********************************


void WIFI_Connect() 
{
  if(app == "Blink") {
    int mytimeout = millis() / 1000;
    #ifdef DEBUG
      Serial.println();
      Serial.println("*********************************************");
    #endif
    Blynk.begin(auth, SSID, PASSWORD);
    
    
    while (Blynk.connected() != WL_CONNECTED) {
      delay(500);
        if((millis() / 1000) > mytimeout + 3){                      // try for less than 4 seconds to connect to WiFi router
        break;
      }
    }
    
    if(!Blynk.connected()) {
      digitalWrite(LED, HIGH);
      #ifdef DEBUG
        Serial.println("NODEMCU Disconnected");
        Serial.println("Reconnecting . . . . . . ");
      #endif
      WIFI_Connect();

      }
    else {
      digitalWrite(LED, LOW);
      #ifdef DEBUG
        Serial.println("Connected. . . . . .");
      #endif 
      // Setup a function to be called every second
      timer.setInterval(1000L, myTimerEvent);
      }
   }
  else {
      delay(10);
      // We start by connecting to a WiFi network
      #ifdef DEBUG
        Serial.println();
        Serial.print("Connecting to ");
        Serial.println(SSID);
      #endif
      WiFi.begin(SSID, PASSWORD);

      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        #ifdef DEBUG
          Serial.print(".");
        #endif
      }

      #ifdef DEBUG
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
      #endif
      client.setServer(MQTT_SERVER , 1883);
      client.setCallback(callback);
    }

     
   }

void loop()  {

  loopstatus = loopstatus + 1 ;
  RX_Data_Recieved = 0;                         // resets the data received bool 
  if(app == "Blynk") {
    if(!Blynk.connected()) {
      Blynk.run();
      timer.run();  
      digitalWrite(LED, HIGH);
      #ifdef DEBUG
         Serial.println("------------------------");
         Serial.println("NODEMCU Disconnected");
         Serial.println("Reconnecting ... ");
      #endif
      WIFI_Connect() ;
      }
    else {
      Blynk.run();
      timer.run();  
      digitalWrite(LED, LOW);         //LED is inverted on a MODEMCU...
      Receive_All_From_MEGA();
      Update_Blynk_App_With_Status();
      #ifdef DEBUG
        Serial.println("");     // new line serial monitor
      #endif
    }
  }
  else {
    if (!client.connected()) {
         digitalWrite(LED, HIGH);
        #ifdef DEBUG
          Serial.println("------------------------");
          Serial.println("NODEMCU MQTT Disconnected");
          Serial.println("Reconnecting ... ");
        #endif
        reconnect();
        Clear_MQTT();
      }
    else {
      client.loop();
      digitalWrite(LED, LOW);         //LED is inverted on a MODEMCU...
      Receive_All_From_MEGA();
      Update_MQTT_With_Status();
      //Serial.println("");     // new line serial monitor
      }
  } 

}
