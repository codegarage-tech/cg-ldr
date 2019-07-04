/*
   Interfacing:
   https://circuitdigest.com/microcontroller-projects/arduino-light-sensor-using-ldr
   https://arduinomylifeup.com/arduino-light-sensor

      PINOUT:
          _____________________________
         |  ARDUINO UNO >>>   LDR  |
          -----------------------------
          GND      >>>   GND(right pin of flat side infront you)
          5v       >>>   VCC(left pin of flat side infront you)
          A0       >>>   OUTPUT(middle)

          Created on: Dec 30, 2018
          Author: Md. Rashadul Alam
          Email: rashed.droid@gmail.com
*/

//int greenLedPin = 2;           // Pin Green LED is connected to
//int yellowLedPin = 3;          // Pin Yellow LED is connected to
//int redLedPin = 4;             // Pin Red LED is connected to
//
//int lightSensorPin = A0;        // PIN Light Sensor is connected to
//int analogValue = 0;
//
//
//void setup() {
//  //Set pins to outputs
//  Serial.begin(9600);
//  pinMode(greenLedPin, OUTPUT);
//  pinMode(yellowLedPin,OUTPUT);
//  pinMode(redLedPin,OUTPUT);
//}
//
//void loop(){
//  analogValue = analogRead(lightSensorPin);
//  Serial.print("analogValue = ");
//  Serial.println(analogValue);
//  if(analogValue < 50){
//    digitalWrite(redLedPin, HIGH);
//  }
//  else if(analogValue >= 50 && analogValue <= 100){
//    digitalWrite(yellowLedPin, HIGH);
//  }
//  else{
//    digitalWrite(greenLedPin, HIGH);
//  }
//  delay(3000);
//  digitalWrite(greenLedPin, LOW);
//  digitalWrite(yellowLedPin, LOW);
//  digitalWrite(redLedPin, LOW);
//}


#define relay 10
int LED = 9;
int LDR = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  int LDRValue = analogRead(LDR);
  Serial.print("sensor = ");
  Serial.print(LDRValue);

  if (LDRValue <= 700)
  {
    digitalWrite(LED, HIGH);
    digitalWrite(relay, HIGH);
    Serial.println(", It's Dark Outside; Lights status: ON");
  }
  else
  {
    digitalWrite(LED, LOW);
    digitalWrite(relay, LOW);
    Serial.println(", It's Bright Outside; Lights status: OFF");
  }

  delay(3000);
}
