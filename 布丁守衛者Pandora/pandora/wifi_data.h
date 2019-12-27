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
const String AK = "STLRBCBLVJGIRlib";//專案金鑰
const String DID = "6020095074647926"; //裝置id box
const String SID_sleep = "Servo"; //可以自己取裝置名稱 sensor id servo
const String SID_sleep2 = "Mercury"; //可以自己取裝置名稱 sensor id servo

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

void post(String IDEASCHAIN_DID, String IDEASCHAIN_AK, String IDEASCHAIN_SID, String value){  //  資料上傳平台
 client.stop();
 if (client.connect("ideaschain.com.tw", 80)) {
  Serial.println("sending data: "+String(value));
    client.print("POST /iot/v1/rawdata/");
    client.print(IDEASCHAIN_DID);
    client.println(" HTTP/1.1");
    client.println("Host: ideaschain.com.tw");
    client.print("AK: ");
    client.println(IDEASCHAIN_AK);    
    client.println("Content-Type: application/json");  ;
    client.print("Content-Length: ");
    client.println(IDEASCHAIN_SID.length()+value.length()+25);
    client.println();
    client.print("[{\"sid\":\"");
    client.print(IDEASCHAIN_SID);
    client.print("\",\"value\":[\"");
    client.print(value);
    client.println("\"]}]");
    } else {
      Serial.println();
      Serial.println("disconnecting from server.");
    }
    delay(3000);
    Serial.println("send end");
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
               Serial.print("value=");
               Serial.println(value);
           }
      }

    } else {
      Serial.println();
      Serial.println("disconnecting from server.");
    }
    delay(1000);
    Serial.println("get end");
   // return value;
}
