#include <Servo.h> 
 int data = 90;
 int ch = 0;
Servo myservo1; // 小腿
Servo myservo2; //腳底
Servo myservo3;
Servo myservo4;
int pos1 = 0;    // variable to store the servo position 
int pos2 = 0;    // variable to store the servo position 
void setup() 
{ 
  Serial.begin(9600);
  myservo1.attach(3);
  myservo2.attach(6);
  myservo3.attach(10);
  myservo4.attach(11);
  pos1 = 0;
  pos2 = 60; 
  pinMode(4, INPUT);   
  pinMode(7, INPUT);            
  pinMode(8, INPUT);          
  pinMode(12, INPUT);            
  pinMode(2, INPUT);           
} 
void loop() 
{ 
  int value1 = pulseIn(2, HIGH);
  int value2 = pulseIn(4, HIGH);
  int value3 = pulseIn(7, HIGH);
  int value4 = pulseIn(8, HIGH);
  int value5 = pulseIn(12, HIGH);
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
  if(value3 < -35)
  {
     if(value1 >20)///我抓/
     {
         pos1 = 150;
         pos2 = 150; 
     }
     else if(value1 <-20) //我抓//我放
     {
         pos1 = 0;
         pos2 = 60;       
     }
  }
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(180-pos1);
  myservo4.write(180-pos2);
  
} 
