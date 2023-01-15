#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sen = A0;
int relay = 8;

int hasil;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sen, INPUT);
  pinMode(relay, OUTPUT);
  lcd.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int kelembapan= analogRead(sen);
  hasil = ( 100 - ( (kelembapan/1023.00) * 100 ) );
  Serial.println(hasil);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Kelembapan");
  lcd.setCursor(1, 1);
  lcd.print("Nilai :");
  lcd.setCursor(7, 1);
  lcd.print(hasil);
  lcd.setCursor(10, 1);
  lcd.print("%");
  

  if (hasil > 20){
    digitalWrite(relay, HIGH);
    lcd.setCursor(13, 1);
    lcd.print("ON");
  }else{
    digitalWrite(relay, LOW);
    lcd.setCursor(13, 1);
    lcd.print("OFF");
  }
  
  delay(1000);

}
