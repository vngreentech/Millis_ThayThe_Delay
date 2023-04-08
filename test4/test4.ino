int choden = 1000;
int choservo = 3000;
unsigned long hientai_den = 0;
unsigned long hientai_servo = 0;
unsigned long thoigian;

int den = 7;

#include <Servo.h>
Servo myservo;
int servo = 8;
int goc_servo;
 
void setup() 
{
  Serial.begin(9600); 

  pinMode(den, OUTPUT);
  myservo.attach(servo);
  myservo.write(0);
}
 
void loop() 
{
//    digitalWrite(den, HIGH);
//    delay(1000);
//    digitalWrite(den, LOW);
//    delay(1000);    
    
    thoigian = millis();
    Serial.print("Time: "); Serial.println(thoigian);
    goc_servo = myservo.read();
    
    if(thoigian - hientai_den >= choden)
    {
        hientai_den = millis();
        Serial.print("              "); 
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

    if (thoigian - hientai_servo >= choservo)
    {
      hientai_servo = millis();
      Serial.print("              "); 
      Serial.print("Hiện tại Servo: "); Serial.print(hientai_servo); Serial.print("     ");
               
      if (goc_servo == 0)
      {
        myservo.write(90);
        Serial.println("Servo: 90");
      }
      else
      {
        myservo.write(0);
        Serial.println("Servo: 0");
      }
    }
}
