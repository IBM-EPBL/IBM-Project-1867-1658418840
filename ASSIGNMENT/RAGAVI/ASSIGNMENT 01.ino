#include <Servo.h>

int output1Value = 0;
int sen1Value = 0;
int sen2Value = 0;
int const gas_sensor = A1;
int const LDR = A0;
int limit = 400;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
// Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_7;

void setup()
{
   Serial.begin(9600);		//initialize serial communication
  pinMode(A0, INPUT);		//LDR
  pinMode(A1,INPUT);      	//gas sensor
  pinMode(13, OUTPUT);		//connected to relay
  servo_7.attach(7, 500, 2500); //servo motor

  pinMode(8,OUTPUT);     	//signal to piezo buzzer
  pinMode(9, INPUT);		//signal to PIR	
  pinMode(10, OUTPUT);		//signal to npn as switch
  pinMode(4, OUTPUT);		//Red LED
  pinMode(3, OUTPUT);		//Green LED
 
}

void loop()
{
  
     //------light intensity control------//
//-------------------------------------------------------------- 
    int val1 = analogRead(LDR);
  if (val1 > 500) 
  	{
    	digitalWrite(13, LOW);
    Serial.print("Bulb ON = ");
    Serial.print(val1);
  	} 
  else 
  	{
    	digitalWrite(13, HIGH);
     Serial.print("Bulb OFF = ");
    Serial.print(val1);
  	}
