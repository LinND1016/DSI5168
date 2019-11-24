#include "wifi_data.h"

#define button 6     // the number of the pushbutton pin
#define reedSwitch 10     // the number of the pushbutton pin
 
int flag = 0;  // 記錄目前狀態
int flag2 = 0; //
int buttonState = 0;         // variable for reading the pushbutton status
int reedSwitchState = 0;         // variable for reading the pushbutton status

void setup()
{
  Serial.begin(9600); 
  Serial.println("START");
  pinMode(button, INPUT);
  pinMode(reedSwitch, INPUT);
  check_wifi();
  Serial.println("Connected to wifi");
}

void loop()
{
  check_wifi();
  buttonState = digitalRead(button); //讀取 button 的狀態
  reedSwitchState = digitalRead(reedSwitch); //讀取 button 的狀態
  Serial.print("button = ");
   Serial.println(buttonState);
  Serial.print("reed = ");
   Serial.println(reedSwitchState);

  if(buttonState == HIGH){  //如果被按下
    if(flag == 0){//防止重複傳送
      flag = 1;
      mypost("button");

    }
  }else{
    flag = 0;
  }

 if(reedSwitchState == LOW){  //如果被吸住
   if(flag2 == 0){//防止重複傳送
      flag2 = 1;  
      mypost("reedSwitch");
 
    }
  }else{
    flag2 = 0;
  }
   
  delay(100);
}
