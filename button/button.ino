#include "wifi_data.h"
#define LED 2


int flag = 0;  // value的值
int buttonState = 0;         // variable for reading the pushbutton status
const int button = 10;     // the number of the pushbutton pin

void setup()
{
  Serial.begin(9600); 
  Serial.println("START");
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  check_wifi();
  Serial.println("Connected to wifi");
  
  //設定 flag 目前的值
  getdata(DID, AK, SID_sleep); //取值
  int flag = (int)*value - 48;//把value的直轉換成 int flag  ASCII .10進位 -48 會等於  圖形數字0 
  if(flag == 0){ //判斷目前的狀態  設定 LED 開關
      flag = 1;
      digitalWrite(LED, HIGH);
   }else{
      flag = 0;
      digitalWrite(LED, LOW);
  }
}

void loop()
{
  check_wifi();
  buttonState = digitalRead(button); //讀取 button 的狀態
  if(buttonState == HIGH){  //如果被按下
    if(flag == 0){ //判斷目前的狀態  
      flag = 1;
      digitalWrite(LED, HIGH);
    }else{
      flag = 0;
      digitalWrite(LED, LOW);
    }
    post(DID, AK, SID_sleep, String(flag)); //上傳目前的狀態
    Serial.println(flag);
  }
  delay(100);
}
