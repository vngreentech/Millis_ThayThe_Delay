int timecho = 1000;
unsigned long hientai = 0;
unsigned long thoigian;
 
void setup() 
{
    Serial.begin(9600); 
}
 
void loop() 
{
//    Serial.println("Green Technology"); 
//    delay(1000);
    
    thoigian = millis();
    
    if(thoigian - hientai > timecho)
    {
        hientai = millis();
        Serial.print("Time: "); Serial.print(thoigian); Serial.print("   "); 
        Serial.print("Hiện tại: "); Serial.print(hientai); Serial.print("   ");
        
        Serial.println("Green Technology"); 
        Serial.println("   ");
    }

}
