#include <RTClib.h>

RTC_DS1307 rtc;

int hours , minutes , seconds = 0;

void setup(){
  Serial.begin(9600);

  if (!rtc.begin()){
    Serial.println("RTC not initialised");
    while(true);
  }
}

void loop(){

  
  String it = in_time();
  String ut = us_time();
  String ft = fr_time();
  Serial.println(it);
  Serial.println(ut);
  Serial.println(ft);

  //  for better working of simulator
  delay(1000);

}

void current_time(){

  DateTime current = rtc.now();
  hours = current.hour();
  minutes = current.minute();
  seconds = current.second();
}

String in_time(){

  current_time();
  String i_t = limit_time(hours , minutes , seconds);
  return "IN Time : " + i_t;
}

String us_time(){

  current_time();
  int u_h = hours - 11;
  int u_m = minutes - 30;
  int u_s = seconds;
  String u_t = limit_time(u_h , u_m , u_s);
  return "US Time : " + u_t;

}

String fr_time(){

  current_time();
  int f_h = hours - 3;
  int f_m = minutes - 30;
  int f_s = seconds;
  String f_t = limit_time(f_h , f_m , f_s);
  return "France Time : " + f_t;

}

String limit_time(int h , int m , int s){

  String t = "";
  if (s > 59){
    s = 0;
    m++;
  }
  else if (s < 0){
    s = 60 - abs(s);
    m--;
  }
  if (m > 59){
    m = 0;
    h++;
  }
  else if (m < 0){
    m = 60 - abs(m);
  }
  if (h > 24  &&  m  ==  0  &&  s  ==  0){
    h = 0 , m = 0 , s = 0;
  }
  else if (h < 0){
    h = 24 - abs(h);
  }

  t = String(h) + " : " + String(m) + " : " + String(s);
  return t;
}