#include "wifi_data.h"
#define reedSwitch 10     // the number of the pushbutton pin
 
int flag = 0; //
int reedSwitchState = 0;         // variable for reading the pushbutton status
int times = 0; // 計算時間
void setup()
{
  Serial.begin(9600); 
  Serial.println("START");
  pinMode(reedSwitch, INPUT);
  check_wifi();
  Serial.println("Connected to wifi");
}

void loop()
{
  check_wifi();
  reedSwitchState = digitalRead(reedSwitch); //讀取 button 的狀態
  Serial.print("reed = ");
  Serial.println(reedSwitchState);
   
  if(reedSwitchState == LOW){  //如果被吸住
   if(flag == 0 && times <=  10){//防止重複傳送  
      mypost();
    }
     flag = 1;    
  }else{//沒被吸
    if(flag == 1){ //重新計時
      times = 0;
    }
    flag = 0;
    times = times + 1; //算時間
 }
   
  delay(100);
}
