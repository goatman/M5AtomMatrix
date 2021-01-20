#include <ArduinoOSC.h>
#include "M5Atom.h"

// WiFi stuff
const char* ssid = "AirStation";
const char* pwd = "";
const IPAddress ip(0, 0, 0, 0);
const IPAddress gateway(192, 168, 0, 1);
const IPAddress subnet(255, 255, 255, 0);

// for ArduinoOSC
const char* host = "192.168.0.103";
const int recv_port = 54321;
const int bind_port = 54345;
const int send_port = 54320;
const int publish_port = 53000;
// send / receive varibales
int i;
float f;
String s;

float roll, pitch, yaw;
bool IMU6886Flag = false;

void setup()
{
    Serial.begin(115200);
    delay(2000);

    // WiFi stuff (no timeout setting for WiFi)
#ifdef ESP_PLATFORM
    WiFi.disconnect(true, true); // disable wifi, erase ap info
    delay(1000);
    WiFi.mode(WIFI_STA);
#endif
    WiFi.begin(ssid, pwd);
    WiFi.config(ip, gateway, subnet);
    while (WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(500); }
    Serial.print("WiFi connected, IP = "); Serial.println(WiFi.localIP());

    M5.begin(true, true, true);

    if (M5.IMU.Init() != 0)
        IMU6886Flag = false;
    else
        IMU6886Flag = true;
}

void loop()
{

   if (IMU6886Flag == true)
    {


        M5.IMU.getAhrsData(&pitch, &roll, &yaw);

        OscWiFi.send(host, send_port, "/yaw", yaw);
        OscWiFi.send(host, send_port, "/pitch", pitch);
        OscWiFi.send(host, send_port, "/roll", roll);
        OscWiFi.update(); // should be called to receive + send osc

  //Serial.printf("%.2f\r\n", yaw);
  //Serial.printf("%.2f\r\n", roll);
  //Serial.printf("%.2f\r\n", pitch);
 
    }

  
    delay(1000/60);
    // or do that separately
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc
}
