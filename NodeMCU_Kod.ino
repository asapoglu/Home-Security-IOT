#define BLYNK_PRINT Serial
#include  <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include  "ThingSpeak.h"
#include <BlynkSimpleEsp8266.h>
#define WLAN_SSID   "Serdengecti"       
#define WLAN_PASSWORD   "123456789."         
unsigned long channelID =1116358;
unsigned  int field_no1=1;
unsigned  int field_no2=2;
unsigned  int field_no3=3;
SoftwareSerial s(D6,D5);
float dataGaz;
float dataSu;
float dataSicaklik;
const char* writeAPIKey = "A2L9ILYJ0NJQU89S";     
const char* readAPIKey  = "B2PFO1K0FUL5B789";
char auth[] = "ms8sxAw-sYO4teEsgkwGHdsHcFskZ6sc";  
WiFiClient  client;
BlynkTimer timer;
void  wifiSetup (){
    delay (10);
    Serial.println(); Serial.println(WLAN_SSID);
        Serial.println(F("Kablosuz  Agina Baglaniyor"));
    WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
    //  WiFi  durum kontrolü
    while (WiFi.status()  !=  WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.print(WLAN_SSID);  Serial.println("Kablosuz  Aga Baglandi");
    Serial.println("IP  adresi: "); Serial.println(WiFi.localIP());
}
void myTimerEvent()
{
  Blynk.virtualWrite(V5, dataSicaklik);
  Blynk.virtualWrite(V6, dataSu);
  Blynk.virtualWrite(V7, dataGaz);
}
void  setup() {
  s.begin(9600);
  Blynk.begin(auth, WLAN_SSID, WLAN_PASSWORD);
  wifiSetup();                    
  ThingSpeak.begin(client);
  timer.setInterval(2000L, myTimerEvent);                 
  Serial.println(F("Kurulum Hazır"));
}
void  loop()  {
  Blynk.run();
  sicaklik();
}
void  sicaklik (){
  dataSu = s.parseFloat();
  delay(100);
  dataGaz = s.parseFloat();
  delay(100);
  dataSicaklik = s.parseFloat();   
  delay(100);
  ThingSpeak.writeField (channelID, field_no1, dataSicaklik, writeAPIKey); 
  ThingSpeak.writeField (channelID, field_no2, dataGaz, writeAPIKey); 
  ThingSpeak.writeField (channelID, field_no3, dataSu, writeAPIKey);  
  timer.run();
}
