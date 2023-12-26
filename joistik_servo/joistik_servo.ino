#include <Servo.h>

Servo motor;

int degerX;
int dereceX;
int degerY;
int dereceY;
int degerC;

void setup() {
  motor.attach(3);
  Serial.begin(9600);
  motor.write(0);
}

void loop() {
  dereceX = 0;
  dereceY = 0;

  // ================ Joistik X Ekseni ================
  degerX = analogRead(A1);
  dereceX = map(degerX, 0, 1023, 0, 180);

  motor.write(dereceX);
  Serial.print("X: " + dereceX);
  Serial.println("");


  // ================ Joistik Y Ekseni ================

  degerY = analogRead(A2);
  dereceY = map(degerY, 0, 1023, 0, 180);

  motor.write(dereceY);
  Serial.print("Y:" + dereceY);
  Serial.println("");


  // ================ Joistik Ortaya Tıklama  ================

  degerC = analogRead(A3);

  Serial.println(degerC);
  if (!degerC) {
    Serial.println("Tuşa tıklandı");
  }

  delay(200);
}