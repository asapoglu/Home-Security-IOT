//Arduino code
#include <SoftwareSerial.h>
SoftwareSerial s(5,6);
float sicaklik; //Analog değeri dönüştüreceğimiz sıcaklık
float analoggerilim; //Ölçeceğimiz analog değer
int sicaklikpin=0; //Analog değer girişi
float gaz;
int gazPin = 1;
int suPin = 2;
float su;
void setup() {
s.begin(9600);
Serial.begin(115200);
}
 
void loop() {
analoggerilim = analogRead(sicaklikpin); //A1'den değeri ölç
gaz = analogRead(gazPin);  
su = analogRead(suPin);
analoggerilim = (analoggerilim/1024)*3300;//değeri mV'a dönüştr
sicaklik = analoggerilim /10; // mV'u sicakliğa dönüştür
s.println(sicaklik);
s.println(gaz);
s.println(su);

delay (1000);
}
