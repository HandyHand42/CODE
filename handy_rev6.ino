#include <Servo.h> 

#define O0 11
#define O1 10
#define O2 9
#define O3 6
#define O4 5
#define O5 3
#define I0 A0
#define I1 A1
#define I2 A2
#define I3 A3
#define I4 A4
#define I5 A5

 
Servo myservo1;
Servo myservo2;
Servo myservo3;
 
 
int pos = 0; 
int moto1 = 1;
int moto2 = 1;
int moto3 = 1;
bool electrode1 = true;
bool reset = false;

const int buttonPin = 11;     // the number of the pushbutton pin
const int ledPin =  9;      // the number of the LED pin
const int analogInPin1 = I0; // Analog input pin that the Hall Sensor isattached to hal1
const int analogInPin2 = I1; // Analog input pin that the Hall Sensor isattached to hal2
const int digitalOutPin= O2; // Digital output pin that the LED isattached to

int sensorValue1 = 0; 
int sensorValue2 = 0;


int buttonState = 0;  


void setup() {
// initialize serial communications at 9600 bps2
Serial.begin(9600);
pinMode(digitalOutPin, OUTPUT);
myservo1.attach(3);
myservo2.attach(5); 
myservo3.attach(6); 



}




void loop() 
{
delay(10);
// read the analog in value:
sensorValue1 = analogRead(analogInPin1);
delay(10);
sensorValue2 = analogRead(analogInPin2);
delay(10);
buttonState = digitalRead(buttonPin);

delay(0);

if (reset==true) {
moto1=1;
moto2=1;
moto3=1;
reset=false;
}


 if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);
  electrode1=false;  
  

}


if (electrode1==false) {
//moving servos

delay(15);
if (sensorValue1>100) {
myservo1.write(moto1++);
}
else
{
electrode1=true;
reset=true;
}

delay(15);
if (sensorValue2>100) {
myservo2.write(moto2++);
}
else
{
electrode1=true;
reset=true;
}


delay(15);
myservo3.write(moto3++);


if (moto1==180) {
  moto1=1;
}

if (moto2==180) {
  moto2=1;
}

if (moto3==180) {
  moto3=1;
}

delay(30); //incase time for hand catch

}





}

//Serial.print("analog val = ");
//Serial.println(sensorValue2);



 
