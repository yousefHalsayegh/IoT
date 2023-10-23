//Make sure you install SevenSeg.h package before running the code
#include "SevenSeg.h"

//defining the pin locations and fucntions
const int trigPin = 3;
const int echoPin = 2;

const int greenLED = 7;
const int yellowLED  = 8;
const int redLED = 6;

// Define segments A-G (A, B, C, D, E, F, G)
SevenSeg disp (4, 5, 10, 11, 12, 13, 9);
const int numOfDigits =1;
int digitPins [numOfDigits]={4};

long duration;
double distance;

double maxDistanceInches = 10; // this is how far we want our sensor to read, ignore everything farther than 12 inches.

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  //Defines the number of digits to be "numOfDigits" and the digit pins to be the elements of the array "digitPins"
  disp.setDigitPins ( numOfDigits , digitPins );
  //Only for common cathode 7segments
  disp.setCommonCathode();
  //Control brightness (values 0-100);
  disp.setDutyCycle(50);

  //sets the LEDs into LOW which is equalto 0
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, LOW);

  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance in cm
  distance = duration * 0.034 / 2;
  distance = distance / 2.54;

  //writes the distance into the display 
  if(distance < maxDistanceInches)
    disp.writeDigit(int(distance));

  else
    disp.writeDigit(0);

  //Light up light depending on distance!
  if(distance < maxDistanceInches)
     digitalWrite(greenLED, HIGH);
     
  else
     digitalWrite(greenLED, LOW);
     
  if(distance < (maxDistanceInches* 0.66))
    digitalWrite(yellowLED, HIGH);
  else
    digitalWrite(yellowLED, LOW);
  
   if(distance < (maxDistanceInches * 0.33)){
    digitalWrite(redLED, HIGH);
   }
   else{
   digitalWrite(redLED, LOW);
   }
  

}


