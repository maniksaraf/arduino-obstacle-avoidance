#include "Button.h"
#include <config.h>
#include <engine.h>
#include <navigation.h>
#include <PololuQTRSensors.h>
#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);
int count = 0;
int sum = 0;

void setup()
{
	Serial.begin(9600);
        engineSetup();
        //calibrate(&qtr);
        //delay(2000);
}
void loop()
{      
	long RangeInInches;
	long RangeInCentimeters;
	RangeInInches = ultrasonic.MeasureInInches();
	RangeInCentimeters = ultrasonic.MeasureInCentimeters();
	Serial.println("The distance to obstacles in front is: ");
	Serial.print(RangeInInches);//0~157 inches
	Serial.println(" inch");
	Serial.print(RangeInCentimeters);//0~400cm
	Serial.println(" cm");
 
        //count = count + 1;
        //sum = sum + RangeInCentimeters;
        //delay (200);
        if (RangeInCentimeters<=20){
          count = 0;  
          Serial.println("This is count");
          Serial.println(count);        
          if (true){
            //Serial.println(sum/3);
            Serial.println("That was sum/3");
            Serial.println(count);
            Serial.println("enters turn loop");
           // digitalWrite(9, HIGH);//press brakes for A
	    //digitalWrite(8, HIGH);//press brakes for A	
            //delay(2000);
            motor(MotorA, 255);
            motor(MotorB, 0);
            delay (1000);
          }
          Serial.println(sum);
          Serial.println("that was the sum");
          sum=0;
        }
        
        //delay (200);
        Serial.println(count);
        Serial.println("exits turn loop");
        
        motor(MotorA,255);
        motor(MotorB,255);
        
}



