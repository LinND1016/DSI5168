#include <HttpClient.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include "sys_api.h"


char ssid[] = "LinND"; //  your network SSID (name) 
char pass[] = "12345677";    // your network password (use for WPA, or use as key for WEP)
const char* host = "192.168.43.157/DSI5168/getsensor.php?sensor=";

int status = WL_IDLE_STATUS;
WiFiClient client;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void check_wifi(){                             //  檢查wifi連線狀況
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("there is no WiFi connected");
//            WiFi.begin(ssid, pass); //("SSID", "password")
    status = WiFi.begin(ssid, pass);
    delay(10*1000);
  }
}



void mypost(){  //  資料上傳平台
// client.stop();
 if (client.connect("192.168.43.157" , 80)) { //連接主機
   client.print("GET /DSI5168/send.php");
    client.println(" HTTP/1.1");
    client.println("Host: 192.168.43.157");
    client.println("Connection: close");
    client.println();
    Serial.println("Updated!");
    client.stop();
    } else {
      Serial.println();
      Serial.println("disconnecting from server.");
    }
    delay(3000);
    Serial.println("send end");
}
