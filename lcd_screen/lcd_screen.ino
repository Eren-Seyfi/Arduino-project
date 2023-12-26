#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define pot A0
#define btn1 9
#define btn2 8
#define Buzzer 10


LiquidCrystal_I2C lcdekranim(0x27, 16, 2);
int Select = 0;
int Back = 0;
int time = 100;
int s1 = 0;


void setup() {
  Serial.begin(9600);
  lcdekranim.init();
  lcdekranim.backlight();
  lcdekranim.clear();
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(Buzzer, OUTPUT);
}


void loop() {

  //  digitalWrite(Buzzer,HIGH);
  //  delay(1000);
  //  digitalWrite(Buzzer,LOW);

  Select = digitalRead(btn1);
  Back = digitalRead(btn2);

  int deger = analogRead(pot);
  Serial.print("Seç === ");
  Serial.print(Select);
  Serial.println("");

  Serial.print("Geri ==== ");
  Serial.print(Back);
  Serial.println("");

  deger = deger / 4;
  deger = deger / 25;

  // LCDScreen(0, 0, newDeger);
  if (deger == 10) {
    LCDScreen(0, 0, "Hoş Geldiniz <=");
    LCDScreen(1, 0, "");
    delay(time);
    lcdekranim.clear();
  } 
  else if (deger == 9) {

    if (Select == 1) {
      s1 = 1;
      if (s1 == 1) {
        LCDScreen(0, 0, "Menu 1.1<=");
        delay(time);
        lcdekranim.clear();
      }
    } else if (Back == 0) {
      s1 = 0;
      if (s1 == 0) {
        LCDScreen(0, 0, "Menu 1 <=");
        LCDScreen(1, 0, "Menu 2");
        delay(time);
        lcdekranim.clear();
      }
    }

  } else if (deger == 8) {
    LCDScreen(0, 0, "Menu 2 <=");
    LCDScreen(1, 0, "Menu 3");
    delay(time);
    lcdekranim.clear();
  } else if (deger == 7) {
    LCDScreen(0, 0, "Menu 3 <=");
    LCDScreen(1, 0, "Menu 4");
    delay(time);
    lcdekranim.clear();
  } else if (deger == 6) {
    LCDScreen(0, 0, "Menu 4 <=");
    LCDScreen(1, 0, "Menu 5");
    delay(time);
    lcdekranim.clear();
  } else if (deger == 5) {
    LCDScreen(0, 0, "Menu 5 <=");
    LCDScreen(1, 0, "Menu 6");
    delay(time);
    lcdekranim.clear();
  }

  else if (deger == 4) {
    LCDScreen(0, 0, "Menu 6 <=");
    LCDScreen(1, 0, "Menu 7");
    delay(time);
    lcdekranim.clear();
  }

  else if (deger == 3) {
    LCDScreen(0, 0, "Menu 7 <=");
    LCDScreen(1, 0, "Menu 8");
    delay(time);
    lcdekranim.clear();
  }

  else if (deger == 2) {
    LCDScreen(0, 0, "Menu 8 <=");
    LCDScreen(1, 0, "Menu 9");
    delay(time);
    lcdekranim.clear();
  }

  else if (deger == 1) {
    LCDScreen(0, 0, "Menu 9 <=");
    LCDScreen(1, 0, "Menu 10");
    delay(time);
    lcdekranim.clear();
  }

  else if (deger == 0) {
    LCDScreen(0, 0, "Menu 9");
    LCDScreen(1, 0, "Menu 10 <=");
    delay(time);
    lcdekranim.clear();
  }

  else {
    LCDScreen(0, 0, "Yanlış giden birşey mevcut");
    lcdekranim.clear();
  }
  //  delay(time);
}

void LCDScreen(int row, int coll, String message) {

  lcdekranim.setCursor(coll, row);
  lcdekranim.print(message);
}