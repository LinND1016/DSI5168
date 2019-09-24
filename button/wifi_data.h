

#include <HttpClient.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <string.h>
#include "sys_api.h"


char ssid[] = ""; //  your network SSID (name) 
char pass[] = "";    // your network password (use for WPA, or use as key for WEP)

/*
*IDEASCHAIN_AK: ideasChain project key.
*IDEASCHAIN_DID: ideasChain device id.
*IDEASCHAIN_SID: ideasChain sensor id.
*/
const String AK = "";//專案金鑰
const String DID = ""; //裝置id
const String SID_sleep = ""; //可以自己取裝置名稱 sensor id

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
