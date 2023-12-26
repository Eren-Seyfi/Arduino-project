

#include "MFRC522.h"

MFRC522 rfid(10, 9);  // Kütüphane tanımlanıyor

String kart = "AB:CD:EF:12";  // Bildiğimiz RFID kartın UID'sini buraya yazalım

void setup() {
  Serial.begin(9600);  // Seri Port Ekranı başlatılıyor
  SPI.begin();         // SPI bağlantısı başlatılıyor
  rfid.PCD_Init();     // Kütüphane başlatılıyor
}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { RFID(); }  // Kart yaklaştırılana kadar bekle
  delay(100);
}

void RFID() {
  rfid.PICC_ReadCardSerial();  // Bağlantı kuruluyor


  Serial.println(kartID());  // Yaklaştırılan kartın seri numarası (UID)


  rfid.PICC_HaltA();  // Kart ile iletişimi sonlandıralım
  rfid.PCD_StopCrypto1();
}

String kartID() {  // Bu bölümde kartın seri numarası onaltılı değere dönüştürülüyor
  String metin = "";
  for (int x = 0; x < rfid.uid.size; x++) {
    if (rfid.uid.uidByte[x] < 10) metin += "0";
    metin += String(rfid.uid.uidByte[x], HEX);
    if (x < rfid.uid.size - 1) metin += ":";
    metin.toUpperCase();
  }
  return metin;
}