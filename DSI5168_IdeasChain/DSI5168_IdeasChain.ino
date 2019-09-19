#include "wifi_data.h"
#define LED 2

int count = 1;

void setup()
{
  Serial.begin(9600); 
  Serial.println("START");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  check_wifi();
  Serial.println("Connected to wifi");
}

void loop()
{
  // put your main code here, to run repeatedly:
  if(count >= 10){
    sys_reset();
  }
  check_wifi();
  
//  digitalWrite(LED, HIGH);
//  post(DID, AK, SID_sleep, String(1));
//  delay(5000);
//  digitalWrite(LED, LOW);
//  post(DID, AK, SID_sleep, String(0));
//  delay(5000);
  getdata(DID, AK, SID_sleep);
  delay(5000);
  count++;
}
