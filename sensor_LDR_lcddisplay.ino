#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

int Con = 100;
const int pin_ldr = 32;

#include <analogWrite.h>

int LedMerah = 18;
int LedKuning = 19;
int LedHijau = 23;

void setup ()
{
  pinMode (LedMerah, OUTPUT);
  pinMode (LedKuning, OUTPUT);
  pinMode (LedHijau, OUTPUT);

  analogWrite(20, Con);
  lcd.begin();
  Serial.begin (9600);
}

void loop ()
{
  int nilai = analogRead (pin_ldr);
  float tegangan_hasil = 5.0 * nilai / 1024;

  if (tegangan_hasil >= 5.00) {
    digitalWrite (LedHijau, HIGH);
    delay(1000);
    digitalWrite (LedHijau, LOW);
    delay(1000);
  }

  if (tegangan_hasil >= 1.00) {
    digitalWrite (LedKuning, HIGH);
    delay(1000);
    digitalWrite (LedKuning, LOW);
    delay(1000);
  }

  if (tegangan_hasil <= 1.00) {
    digitalWrite (LedMerah, HIGH);
    delay(1000);
    digitalWrite (LedMerah, LOW);
    delay(1000);
  }

    Serial.print ("Vout = ");
    Serial.print (tegangan_hasil);
    Serial.println ("V");

    lcd.setCursor(4, 1);
    lcd .print ("_Sensor LDR_");

    lcd.setCursor(4, 2);
    lcd.print ("Vout = ");
    lcd.print(tegangan_hasil);
    lcd.print("V");
    
    delay (2000);
  }
