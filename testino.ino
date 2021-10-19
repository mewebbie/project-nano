#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>

RF24 radio(7,6);
const byte address[6] = "00001";

#define echoPin 9
#define trigPin 8

long distance;
int duration;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.stopListening();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() { 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  delay(100);
  distance = (duration*0.034/2);
  Serial.println(distance);
  radio.write(&distance, sizeof(long));
  delay(1000);
}
