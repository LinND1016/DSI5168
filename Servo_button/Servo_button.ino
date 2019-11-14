#include "wifi_data.h"
#define LED 2
#define button 10     // the number of the pushbutton pin
#include <AmebaServo.h>

AmebaServo myservo;  // create servo object to control a servo
// 4 servo objects can be created correspond to PWM pins

int pos = 0;    // variable to store the servo position
int flag = 0;  // 記錄目前狀態
int buttonState = 0;         // variable for reading the pushbutton status
void setup()
{
  Serial.begin(9600); 
  Serial.println("START");
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
  myservo.attach(12); // attaches the servo on pin 9 to the servo object
  myservo.write(90); 
  check_wifi();
  Serial.println("Connected to wifi");
}

char str[] ="YES";
void loop()
{
  check_wifi();
  buttonState = digitalRead(button); //讀取 button 的狀態
  if(buttonState == HIGH){  //如果被按下
    if(flag == 0){ //判斷目前的狀態  
      flag = 1;
      int i = random(0,180);
       myservo.write(i);
       Serial.println(i);
      digitalWrite(LED, HIGH);
      if(i >= 90){
        str[0] = 'y';
        str[1] = 'e';
        str[2] = 's';
      }else{
        str[0] = 'n';
        str[1] = 'o';
        str[2] = 0;
      }
      Serial.println(str);
      post(DID, AK, SID_sleep, String(str)); //上傳目前的狀態
  }}
  else{
      flag = 0;
      digitalWrite(LED, LOW);
   }
  Serial.println(flag);
  delay(100);
}
