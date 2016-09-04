#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float adc1,adc2,v,i,E=0;
unsigned long int t1,t2,tu1=0,tu2;

void setup()
{
  lcd.begin(16, 2);

}

void loop() 
{
t1=micros();

adc1=analogRead(A0);
adc2=analogRead(A1);

v=((adc1/1023)*5-2.35)*230/1.3;
i=((adc2/1023)*5-2.35)*0.22/0.25;

t2=micros();

E=E+v*i*(t2-t1)/3600000000;

tu2=millis();

if((tu2-tu1)>4000)
{
  lcd.setCursor(0,0);
  lcd.print("E=");
  lcd.print(E);
  lcd.print(" Wh");
  tu1=millis();
}
}
