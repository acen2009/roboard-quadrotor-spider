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
} 
 
 
void loop() 
{ 
   while (Serial.available() > 0) {
     data = Serial.read();
     if(data == 'a')
       ch = 1;
     else if(data == 'b')
       ch = 2;    
     else if(ch == 1) 
     {
       if(data == 'q')
         pos1 = pos1+10;
       else if(data == 'w')
         pos1 = pos1-10;
     }
     else if(ch == 2)
     {
       if(data == 'q')
         pos2 = pos2+10;
       else if(data == 'w')
         pos2 = pos2-10;
     }
     if(data == 'z') //我放
     {
         pos1 = 0;
         pos2 = 60; 
     }
     else if(data == 'x') //我抓
     {
         pos1 = 150;
         pos2 = 150;        
     }
   }
  
  Serial.print("ch =  ");
  Serial.print(ch);
  Serial.print("  pos1 =  ");
  Serial.print(pos1);
  Serial.print("  pos2 =  ");
  Serial.println(pos2);
  delay(300);
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(180-pos1);
  myservo4.write(180-pos2);

} 
