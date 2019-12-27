#include "wifi_data.h"

int replaycount = 0;
int countvalue = 0;

void setup()
{
  Serial.begin(9600); 
  check_wifi();
  Serial.println("Connected to wifi");
}

void loop()
{
  if(replaycount%10 == 0 && replaycount!=0){
    countvalue = replaycount/5;
    mypost(countvalue, replaycount);
    Serial.print("send mail:");
  }
  else{
    getdata(DID, AK);
    Serial.print("Get value:");
    Serial.println(value);
  }
  replaycount ++;
  delay(50);
}
