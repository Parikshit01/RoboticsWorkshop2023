//motor driver setting voltage=8.8V
#include <Encoder.h>
Encoder myEnc(2,3);
int set_pos;
float currentpos;
float error1, error2;
int m1_enable=6,m1_dir1=7,m1_dir2=8;
void setup()
{
Serial.begin(115200);
pinMode(m1_enable, OUTPUT);
pinMode(m1_dir1, OUTPUT);
pinMode(m1_dir2, OUTPUT);
}

void loop()

{set_pos = Serial.parseInt();
   while(Serial.available()>0)
   {
     //set_pos = Serial.parseInt(); //read int or parseFloat for ..float...
       Serial.print(" set_pos ");
       Serial.print(set_pos);
        if (set_pos > 0)
        {
        digitalWrite(m1_dir1, LOW);
        digitalWrite(m1_dir2, HIGH);
        analogWrite(m1_enable,65);
        

         currentpos =  myEnc.read();
        Serial.print("  currentpos:");
        Serial.println(currentpos/1544.44);        
        error1= abs(abs(set_pos)-abs(currentpos/1544.44));
        if(error1<=1) 
        {
        digitalWrite(m1_dir1, HIGH);
        digitalWrite(m1_dir2, HIGH);
        analogWrite(m1_enable,65);
        delay(300000);
        currentpos =   myEnc.read();

       //  Serial.print("currentpos:");
       // Serial.print(currentpos/1544.44);
        }

       
        } 

        
        if (set_pos < 0){
        analogWrite(m1_enable,65);
        digitalWrite(m1_dir1, HIGH);
        digitalWrite(m1_dir2, LOW);
        currentpos =  myEnc.read();
         Serial.print("  currentpos:");
        Serial.println(currentpos/1544.44);
       
        error2= abs(abs(set_pos)-abs(currentpos/1544.44));
        if(error2<=1) 
        { 
          digitalWrite(m1_dir1, HIGH);
          digitalWrite(m1_dir2, HIGH);
          analogWrite(m1_enable,65);
        delay(300000);
        //Serial.print("currentpos:");
        //Serial.println(-1*float(currentpos)/1544.44);
        }
   }
//        digitalWrite(m1_dir1, LOW);
//        digitalWrite(m1_dir2, HIGH);
//        analogWrite(m1_enable,65);
//        pos =  myEnc.read();
//        Serial.println(pos/1544.44);
//        delay(200000);
//        digitalWrite(m1_dir1, HIGH);
//        digitalWrite(m1_dir2, HIGH);
//        analogWrite(m1_enable,65);
//        pos =  myEnc.read();
//        Serial.println(pos/1544.44);
//        delay(200000);
//        digitalWrite(m1_dir1, HIGH);
//        digitalWrite(m1_dir2, LOW);
//        analogWrite(m1_enable,65);
//        pos =  myEnc.read();
//        Serial.println(pos/1544.44);
//        delay(200000);
//        digitalWrite(m1_dir1, HIGH);
//        digitalWrite(m1_dir2, HIGH);
//        analogWrite(m1_enable,65);
//        delay(200000);
//        Serial.println(pos/1544.44);

        

   }

   }
        
        
