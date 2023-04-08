
//millis trả về thời gian (tính theo mili giây) kể từ lúc Arduino bắt đầu chương trình.

unsigned long thoigian; //Kiểu số nguyên từ 0 đến 4,294,967,295 (4 tỷ)

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  thoigian = millis();
  
  Serial.print("Thời gian: ");
  Serial.println(thoigian);

  delay(100);
}
