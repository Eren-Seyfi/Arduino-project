/*
Lezzetli Robot Tarifleri
https://lezzetlirobottarifleri.com/joystick-modulu-arduino-ile-nasil-kullanilir
*/

const int x_ekseni = A1;
const int y_ekseni = A2;

int x_durum;
int y_durum;

void setup() {
Serial.begin(9600);
}

void loop() {
  x_durum = analogRead(x_ekseni);
  y_durum = analogRead(y_ekseni);

  Serial.print("x durumu = ");
  Serial.println(x_durum);
  Serial.print("y durumu = ");
  Serial.println(y_durum);
  delay(1000);
}