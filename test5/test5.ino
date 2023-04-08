int choden = 5000;
unsigned long hientai_den = 0;
unsigned long thoigian;

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
    
    thoigian = millis();
    Serial.print("Time: "); Serial.println(thoigian);
    
    if(thoigian - hientai_den >= choden)
    {
        hientai_den = millis();
        Serial.print("                        "); 
        Serial.print("Hiện tại Đèn: "); Serial.print(hientai_den); Serial.print("     ");     
        
        if (digitalRead(den) == LOW)
        {
          digitalWrite(den, HIGH);
          Serial.println("Đèn ON");
        }
        else
        {
          digitalWrite(den, LOW);
          Serial.println("Đèn OFF");
        }
    }
}
