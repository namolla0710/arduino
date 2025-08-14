#include <Servo.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h>
#endif

Servo myservo;

#define PIN 12
#define NUMPIXELS 12 

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define TRIG 8
#define ECHO 7

int pos = 0;
double pot = 180 / 7;

void setup() {
  myservo.attach(9);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif

  pixels.begin();

  pinMode(4, OUTPUT);

  Serial.begin(9600);
}

void setColor(int is){
  long duration, distance;
  digitalWrite(TRIG, LOW);  
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);

  distance = duration * 17 / 1000;

  if(distance < 20){
    pixels.setPixelColor(is+3, pixels.Color(200, 0, 0));
    pixels.setBrightness(150);
    pixels.show();
  } else {
    pixels.setPixelColor(is+3, pixels.Color(0, 200, 0));
    pixels.setBrightness(150);
    pixels.show();
  }
}

void loop()
{
  

  for(int pos = 0; pos < 180; pos++){
    myservo.write(pos);
    if(pos < pot *1 +1 && pos > pot *1 -1){
      setColor(1);
    } else if(pos < pot *2 +1 && pos > pot *2 -1){
      setColor(2);
    } else if(pos < pot *3 +1 && pos > pot *3 -1){
      setColor(3);
    } else if(pos < pot *4 +1 && pos > pot *4 -1){
      setColor(4);
    } else if(pos < pot *5 +1 && pos > pot *5 -1){
      setColor(5);
    } else if(pos < pot *6 +1 && pos > pot *6 -1){
      setColor(6);
    } else if(pos < pot *7 +1 && pos > pot *7 -1){
      setColor(7);
    }

    delay(15);
    if(pos % 30 == 0){
      tone(4, 20, 50);
    }
  }
  for(int pos = 180; pos > 0; pos--){
    myservo.write(pos);
    if(pos < pot *1 +1 && pos > pot *1 -1){
      setColor(1);
    } else if(pos < pot *2 +1 && pos > pot *2 -1){
      setColor(2);
    } else if(pos < pot *3 +1 && pos > pot *3 -1){
      setColor(3);
    } else if(pos < pot *4 +1 && pos > pot *4 -1){
      setColor(4);
    } else if(pos < pot *5 +1 && pos > pot *5 -1){
      setColor(5);
    } else if(pos < pot *6 +1 && pos > pot *6 -1){
      setColor(6);
    } else if(pos < pot *7 +1 && pos > pot *7 -1){
      setColor(7);
    }

    delay(15);
    if(pos % 30 == 0){
      tone(4, 20, 50);
    }
  }
}