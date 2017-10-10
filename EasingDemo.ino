#include <Arduino.h>
#include "easing.h"
#include <Servo.h>

Servo oneServo;
Servo twoServo;
Servo threeServo;


int oneServoPin = 9;
int twoServoPin = 6;
int threeServoPin = 8;

float iterations = 2000; // Iterationer pr animation

float pos = 0;
float oneServoPos = 0;
float twoServoPos = 0;
float threeServoPos = 0;


void setup() {
    oneServo.attach(oneServoPin);
    twoServo.attach(twoServoPin);
    threeServo.attach(threeServoPin);

    oneServo.write(0);
    twoServo.write(0);
    threeServo.write(0);
    
    
    delay(1000);

}

void loop() {
    for (pos = 0; pos <= iterations; pos++) {

        oneServoPos = 10 + 160 * ExponentialEaseOut(pos/iterations);
        twoServoPos = 10 + 160 * BounceEaseOut(pos/iterations);
        threeServoPos = 10 + 160 * pos/iterations;

        
        oneServo.write(oneServoPos);
        twoServo.write(twoServoPos);
        threeServo.write(threeServoPos);
        
        delay(1);
    }


    for (pos = iterations; pos >= 0; pos--) {
      
      oneServoPos = 10 + 160 * ExponentialEaseIn(pos/iterations);
      twoServoPos = 10 + 160 * BounceEaseIn(pos/iterations);
      threeServoPos = 10 + 160 * pos/iterations;

        
        
        oneServo.write(oneServoPos);
        twoServo.write(twoServoPos);
        threeServo.write(threeServoPos);
        
        delay(1);
    }

    delay(1000);
}
