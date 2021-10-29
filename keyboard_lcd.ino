#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

const byte rows = 4;
const byte cols = 4;

char hexaKeys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[rows] = {A0,A1,A2,A3};
byte colPins[cols] = {5,4,3};
LiquidCrystal_I2C lcd(0x27, 16, 2);
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, rows, cols);
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  lcd.init();
  lcd.begin(16,2);
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  if(customKey){
    //Serial.println(customKey);
    lcd.print(customKey);
  }

}
