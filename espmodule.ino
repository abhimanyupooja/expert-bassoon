
#define BLYNK_PRINT Serial
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <SoftwareSerial.h>
#define ESP8266_BAUD 115200
const int led=9;
const int sensor=5;
int state=LOW;
int val=0;

char auth[]="JaQhNM5_fDbHKWjuFYRK36_f-ln8msN";
char ssid[]="Redmi7A";
char pass[]="praveen23";
int Buzzer=7;
SoftwareSerial EspSerial(0,1);
WidgetLCD lcd(V0);
ESP8266 wifi(&EspSerial);

void setup()
{
  Serial.begin(115200);
  EspSerial.begin(ESP8266_BAUD);
  Blynk.begin(auth,wifi,ssid,pass);
  lcd.clear();
  lcd.print(1,1,"IOT");
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT);
  pinMode(Buzzer,OUTPUT);    
  Serial.begin(115200); 
}
void loop()
{
  Blynk.run();
  val=digitalRead(sensor);
  if(val==HIGH)
  {
    digitalWrite(led,HIGH);
    delay(500);
    if(state==LOW)
    {
      Serial.println("Motion Detected");
      digitalWrite(Buzzer,HIGH);
      delay(1000);
      digitalWrite(Buzzer,LOW);
      delay(1000);
      state=HIGH;
    }
  }
  else{
    digitalWrite(led,LOW);
    delay(500);
    if(state==HIGH){
      Serial.println("The action is not supported");
      state=LOW;
    }
  }
}
