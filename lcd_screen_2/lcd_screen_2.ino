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
String menus[] = {"Hoş Geldiniz", "Menu 1", "Menu 2", "Menu 3", "Menu 4", "Menu 5", "Menu 6", "Menu 7", "Menu 8", "Menu 9", "Menu 10"};
int currentMenu = 0;

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
  Select = digitalRead(btn1);
  Back = digitalRead(btn2);

  // Potansiyometre değeri 1 ile 10 arasına ölçekleniyor
  int deger = map(analogRead(pot), 0, 1023, 1, 10);

  if (deger != currentMenu) {
    currentMenu = deger;
    displayMenu(currentMenu);
  }

  if (Select == HIGH) {
    if (s1 == 0) {
      s1 = 1;
      displaySubMenu(currentMenu);
    }
  } else if (Back == HIGH) {
    if (s1 == 1) {
      s1 = 0;
      displayMenu(currentMenu);
    }
  }

  delay(time);
}

void displayMenu(int menuIndex) {
  lcdekranim.clear();
  LCDScreen(0, 0, menus[menuIndex]);
  if (menuIndex < 10) {
    LCDScreen(1, 0, menus[menuIndex + 1]+"<=");
  }
}

void displaySubMenu(int menuIndex) {
  lcdekranim.clear();
  LCDScreen(0, 0, "SubMenu " + String(menuIndex + 1) + ".1");
}

void LCDScreen(int row, int coll, String message) {
  lcdekranim.setCursor(coll, row);
  lcdekranim.print(message);
}
