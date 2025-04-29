#include <SevSeg.h>

const byte D1 = 13, D2 = 5, D3 = 4, D4 = 3, B = 2;
const byte A = 6, F = 7, G = 8, C = 9, dp = 10, D = 11, E = 12;

SevSeg sevseg;
byte numDigits = 4;
byte digitPins[] = {D1, D2, D3, D4};
byte segmentPins[] = {A, B, C, D, E, F, G, dp};
bool resistorsOnSegments = true;
byte hardwareConfig = COMMON_CATHODE;
int userInput;
int delayTime = 5;
int buzzPin = A2;

void setup() {
  // put your setup code here, to run once:
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins,
  resistorsOnSegments);
  sevseg.setBrightness(90);
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() == 0) {
    Serial.println("set a timer for seconds, maximum: 9999");
    while(Serial.available() == 0){

    }
  }
  
  userInput = Serial.parseInt();
  if (userInput <= 9999 && userInput > 0){
    while(userInput > 0){
      sevseg.setNumber(userInput);
      for(int i=0; i < 200; i++){
        sevseg.refreshDisplay();
        delay(delayTime);
      }

      sevseg.refreshDisplay();
      userInput = userInput - 1;
      sevseg.refreshDisplay();
    }
    for (int i=0; i < 10; i++){
      analogWrite(buzzPin, 255);
      delay(100);
      analogWrite(buzzPin, 0);
      delay(100);
    }
    
    sevseg.blank(); // clear display
  } else{
    Serial.println("Maximum number is 9999, please try again!");
    delay(1000);
  }
}


