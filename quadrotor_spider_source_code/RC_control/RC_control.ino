void setup() {
  pinMode(4, INPUT);   
  pinMode(7, INPUT);            
  pinMode(8, INPUT);          
  pinMode(12, INPUT);            
  pinMode(2, INPUT);           
        
  Serial.begin(9600);                     
}

void loop() {
  int value1 = pulseIn(4, HIGH);
  int value2 = pulseIn(7, HIGH);
  int value3 = pulseIn(8, HIGH);
  int value4 = pulseIn(12, HIGH);
  int value5 = pulseIn(2, HIGH);
  value1 = value1/10 - 149;
  value2 = value2/10 - 149;
  value3 = value3/10 - 149;
  value4 = value4/10 - 149;
  value5 = value5/10 - 149;  
  Serial.print(value1);
  Serial.print("   ");
  Serial.print(value2);
  Serial.print("   ");
  Serial.print(value3);
  Serial.print("   ");
  Serial.print(value4);
  Serial.print("   ");
  Serial.print(value5);
  Serial.println("   ");
  delay(25);
}
