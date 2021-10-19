#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>

RF24 radio(7,6);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.startListening();
}

void loop() {
  if(radio.available()) {
    digitalWrite(13,HIGH);
    long text = 0.0;
    radio.read(&text,sizeof(long));
    if(text < 15) {
      for(int i=0;i<5;i++) {
        tone(9, 1000);
        delay(1000);
        noTone(buzzer);
        delay(100); 
      }
    }
    delay(100);
    Serial.print(text);
    Serial.print("cm\n");
    digitalWrite(13,LOW);
  }
} 
