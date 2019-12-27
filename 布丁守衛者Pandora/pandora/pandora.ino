#include "wifi_data.h"
#include <AmebaServo.h>
 
AmebaServo  myservo;
int Mercurycount  = 0;
int boxlocked  = 1;
int pos = 0;
int count = 0;

const int Mercuryswitch = 10;
//const int relay = 13;
void setup()
{
  Serial.begin(9600); 
  Serial.println("START");
  pinMode(Mercuryswitch, INPUT);
  check_wifi();
  Serial.println("Connected to wifi");
   myservo.attach(12); // attaches the servo on pin 9 to the servo object
   myservo.write(15);
}

void loop()
{
  count = count + 1;
  if(count == 100){// 每5秒 get 
    count = 0;
    //取 是否需要Lock
    getdata(DID, AK); //DID Servo (Lock)
    Serial.print("main value:");
    Serial.println(value);
    int A = (int)*value;
    Serial.print("main A:");
    A = A - 48;
    Serial.println(A);
    //A = 1 LOCK 
    if(A == 1){
        boxlocked = 1;
        myservo.write(100);
    }
    else{//A = 0 UNLUCK
       boxlocked = 0; 
       myservo.write(15); 
    }
  }

  //如果是lock 才要算搖晃 次數
  if(boxlocked == 1){
    int MercuryStatus = digitalRead(Mercuryswitch); //取有無搖晃
     Serial.print("MercuryStatus = ");
     Serial.println(MercuryStatus);
    if(MercuryStatus == HIGH){//搖晃
      char  str[] = "shake";
       post(DID, AK, SID_sleep2, String(str));  // 搖晃int val = 1;
    }
  }
  delay(50);
}
