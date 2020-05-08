//choose beetwen Blynk or MQTT

//const char* app = "Blynk";
const char* app = "MQTT";


// Your WiFi credentials.
// Set password to "" for open networks.
#define SSID                          "WIFI NAME"
#define PASSWORD                      "WIFI Password"

// Blynk settings
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Blynk Token Number";


// MQTT Settings
#define HOSTNAME                      "MOWER"
#define MQTT_SERVER                   "192.168.1.32"
#define QUICKSTART_TOPIC              "home/garden/mower/quickstart"
#define GODOCK_TOPIC                  "home/garden/mower/godock"
#define PAUSESTOP_TOPIC               "home/garden/mower/pausestop"
#define EXITDOCK_TOPIC                "home/garden/mower/exitdock"
#define CHARGING_TOPIC                "home/garden/mower/charging"
#define TRACKING_TOPIC                "home/garden/mower/tracking"
#define PARKED_TOPIC                  "home/garden/mower/parked"
#define MOVE_TOPIC                    "home/garden/mower/move"
#define DOCKED_TOPIC                  "home/garden/mower/docked"
#define FWD_TOPIC                     "home/garden/mower/fwd"
#define LEFT_TOPIC                    "home/garden/mower/left"
#define RIGHT_TOPIC                   "home/garden/mower/right"
#define REV_TOPIC                     "home/garden/mower/rev"
#define AVAILABILITY_TOPIC            "home/garden/mower/online"
#define SPIRAL_TOPIC                  "home/garden/mower/spiralmowing"   
#define RANDOM_TOPIC                  "home/garden/mower/randommowing"
#define PARALLEL_TOPIC                "home/garden/mower/parallelmowing"
#define MANUEL_TOPIC                  "home/garden/mower/manuel"


#define mqtt_username                 "mqtt_username"
#define mqtt_password                 "mqtt_password"



//DEBUG MODE

//#define DEBUG    //uncomment to activate
