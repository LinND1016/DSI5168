#include <HttpClient.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <string.h>
#include "sys_api.h"


char ssid[] = "LinND"; //  your network SSID (name) 
char pass[] = "12345677";    // your network password (use for WPA, or use as key for WEP)

/*
*IDEASCHAIN_AK: ideasChain project key.
*IDEASCHAIN_DID: ideasChain device id.
*IDEASCHAIN_SID: ideasChain sensor id.
*/
const String AK = "mj3TDDUzY8Oru2H5";//專案金鑰
const String DID = "7590582701435470"; //裝置id
const String SID_sleep = "1234"; //可以自己取裝置名稱 sensor id

int status = WL_IDLE_STATUS;
WiFiClient client;

//json object
const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(1) + 60;
DynamicJsonBuffer jsonBuffer(capacity);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void check_wifi(){                             //  檢查wifi連線狀況
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("there is no WiFi connected");
//            WiFi.begin(ssid, pass); //("SSID", "password")
    status = WiFi.begin(ssid, pass);
    delay(10*1000);
  }
}

void mypost(int value, int value2){  //  資料上傳平台
// client.stop();
 if (client.connect("192.168.43.157" , 80)) { //連接主機
  Serial.println("sending data: "+String(value));
   client.print("GET /DSI5168/send.php");
    client.print("?value=");
    client.print(value);
    client.print("&total=");
    client.print(value2);
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
}

 const char* value;
 
void getdata(String IDEASCHAIN_DID, String IDEASCHAIN_AK){  //  資料下載
  
 client.stop();
 if (client.connect("ideaschain.com.tw", 80)) {
  // We now create a URI for the request
      String url = "/iot/v1/rawdata/" + IDEASCHAIN_DID;
      // This will send the request to the server
      client.print("GET " + url + " HTTP/1.1\r\n" +
                   "Host: " + "ideaschain.com.tw" + "\r\n" +
                   "AK:"+ IDEASCHAIN_AK + "\r\n" +
                   "Content-Type: application/json\r\n" + 
                   "Connection: close\r\n\r\n");
      delay(500);
    //取資料印出來
      while(client.available())
      {
        String line = client.readStringUntil('\r'); 
       //Serial.println(line); 
        char str[256];
        line.toCharArray(str, 256);
        if(str[2] == '{'){//是json array 格式
           JsonArray& root = jsonBuffer.parseArray(line);
           if(!root.success()){
               Serial.println("parseObject() failed");
             }
               value = root[0]["value"][0];
              // a =root[1]["value"][0];
               Serial.print("value=");
               Serial.println(value);
           }
      }

    } else {
      Serial.println();
      Serial.println("disconnecting from server.");
    }
    delay(1000);
   // return value;
}
