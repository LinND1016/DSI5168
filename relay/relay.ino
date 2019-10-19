#include "wifi_data.h"
#define relay 12

void setup()
{
  Serial.begin(9600); 
  Serial.println("START");
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  check_wifi();
  Serial.println("Connected to wifi");
}

void loop()
{
  check_wifi();

  getdata(DID, AK);
  Serial.print("main value:");
  Serial.println(value);
   int A = (int)*value;
     Serial.print("main A:");
     A = A - 48;
  Serial.println(A);
  if(A == 1){
      digitalWrite(relay, LOW);
      Serial.print("High");
   }
   else{
      digitalWrite(relay, HIGH);
      Serial.print("LOW");
   }
  delay(100);
}
