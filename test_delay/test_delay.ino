int den = 7;
int bientro = A0; int gtbientro; int gtbiendoi;

#include <Servo.h>
Servo myservo;
int servo = 8;
 
void setup() 
{
  Serial.begin(9600); 

  pinMode(den, OUTPUT);
  pinMode(bientro, INPUT);
  myservo.attach(servo);
}
 
void loop() 
{  
    gtbientro = analogRead(bientro);
    gtbiendoi = map(gtbientro, 0, 1023, 0, 180);
    myservo.write(gtbiendoi);
    Serial.print("Servo: "); Serial.print(gtbiendoi); Serial.print("   ");
    
    digitalWrite(den, HIGH);
    delay(3000);
    digitalWrite(den, LOW);
    delay(3000);
}
