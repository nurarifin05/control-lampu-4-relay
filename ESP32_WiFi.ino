#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <CTBot.h>

char auth[] = "YUmhG02IQj0bdEG189LxCdwaQgTqwTtv";
char ssid[] = "my_seamless";
char pass[] = "oke12345";
String token = "1887348468:AAGkxPXNTBFrTU6Wqtq5MxtTs712F0wgVpY";
const int id = 893370318;

#define ldrPin_1 15
#define ldrPin_2 2
#define ldrPin_3 4 
#define ldrPin_4 5
BlynkTimer timer;
CTBot myBot;

void sendSensor(){
  String Mati = "Lampu Dalam Kondisi Mati";
  String Hidup = "Lampu Dalam Kondisi Hidup";
  
  int sensorValue1 = digitalRead(ldrPin_1);
  int sensorValue2 = digitalRead(ldrPin_2);
  int sensorValue3 = digitalRead(ldrPin_3);
  int sensorValue4 = digitalRead(ldrPin_4);
  
  if(sensorValue1 == 0){
    Blynk.virtualWrite(V5, Mati);
    Serial.println("Mengirimkan Notifikasi Lampu Mati");
  }else if(sensorValue1 == 1){
    Blynk.virtualWrite(V5, Hidup);
    Serial.println("Mengirimkan Notifikasi Lampu Menyala");
  }else if(sensorValue2 == 0){
    Blynk.virtualWrite(V6, Mati);
    Serial.println("Mengirimkan Notifikasi Lampu Mati");
  }else if(sensorValue2 == 1){
    Blynk.virtualWrite(V6, Hidup);
    Serial.println("Mengirimkan Notifikasi Lampu Menyala");
  }else if(sensorValue3 == 0){
    Blynk.virtualWrite(V7, Mati);
    Serial.println("Mengirimkan Notifikasi Lampu Mati");
  }else if(sensorValue3 == 1){
    Blynk.virtualWrite(V7, Hidup);
    Serial.println("Mengirimkan Notifikasi Lampu Menyala");
  }else if(sensorValue4 == 0){
    Blynk.virtualWrite(V8, Mati);
    Serial.println("Mengirimkan Notifikasi Lampu Mati");
  }
  else if(sensorValue4 == 1){
    Blynk.virtualWrite(V8, Hidup);
    Serial.println("Mengirimkan Notifikasi Lampu Menyala");
  }
  
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sendSensor);
  myBot.setTelegramToken(token);
  if (myBot.testConnection()) {
    Serial.println("Koneksi Bagus");
  } else {
    Serial.println("Koneksi Jelek");
  }

  myBot.sendMessage(id, "Alat Menyala");
  Serial.println("Pesan Terkirim");
}

void loop()
{
  Blynk.run();
  timer.run();
}
