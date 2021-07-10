#include <FastLED.h>

#define LEDPIN     5
#define NUMOFLEDS    20

CRGB leds[NUMOFLEDS];

 const int ref=500;

int val=0;  //stores the val from piezo disc
int count=1; //keeps tracks of led effects

bool state=false;  //is state is true, the lamp is turn on and if false the leds are turned off
bool first=false;   //first is only true when the state goes true for the first time and helps to turn on the indicator led on lamp when the state goes true

void setup() {
  Serial.begin(9600);
  pinMode(A3,INPUT);
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  FastLED.setBrightness(30);
  FastLED.addLeds<WS2812B, LEDPIN, GRB>(leds, NUMOFLEDS);
  //attaching interrupt at int0 pin 
  attachInterrupt(0,ENABLE,RISING);
    goblack();

}

void loop() {
  if(state && first){
    first=false;
    leds[9] = CRGB (255, 90, 0);
  FastLED.show();
  leds[10] = CRGB (255, 150, 0);
  FastLED.show();
  }
  val= analogRead(A3);
  if(state && val>ref){
    change(count);
  }
  else if(!state) {
    goblack();
    leds[9] = CRGB (0, 0, 0);
  FastLED.show();
  leds[10] = CRGB (0, 0, 0);
  FastLED.show();
  }

  }

//ISR which also handle debounce changes the state very time it is triggered

void ENABLE(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) 
  {
    if(state) state=false;
    else{
      state=true;
      first=true;
    }
  }
  last_interrupt_time = interrupt_time;
}

void change(int x){

   switch(x){

    case 1: goblack();
    white();
    break;
    case 2: goblack();
    rainbow();
    break;
    case 3: goblack();
    flag();
    break;
    case 4: goblack();
    cool();
    break;
    case 5: red();
    break;
    case 6: green();
    break;
    case 7: blue();
    break;
    case 8: goblack();
    intro();
    break;
    case 9: goblack();
    break;
   }
  count++;
  if(count>9){
    count=1;
  }
}


/*
 * all the functions under are simply individually addressed led effect
 * 
 */
void rainbow(){
   
  //first row
  leds[15] = CRGB (255,0, 0);
  FastLED.show();
  delay(60);
  leds[16] = CRGB (255, 165, 0);
  leds[14] = CRGB (255, 165, 0);
  FastLED.show();
  delay(60);
  leds[17] = CRGB (255,255,0);
  leds[13] = CRGB (255,255,0);
  leds[5] = CRGB (255,255,0);
  FastLED.show();
  delay(60);
  leds[18] = CRGB (0,128,0);
  leds[12] = CRGB (0,128,0);
  leds[6] = CRGB (0,128,0);
  leds[4] = CRGB (0,128,0);
  FastLED.show();
  delay(60);
  leds[11] = CRGB (0,0,255);
  leds[7] = CRGB (0,0,255);
  leds[3] = CRGB (0,0,255);
  FastLED.show();
  delay(60);
  leds[8] = CRGB (75,0,130);
  leds[2] = CRGB (75,0,130);
  FastLED.show();
  delay(60);
  leds[1] = CRGB (238,130, 238);
  FastLED.show();
  delay(60);
}



void white(){
  leds[1] = CRGB (255,255,225);
  FastLED.show();
  delay(20);
  leds[2] = CRGB (255, 255, 225);
  FastLED.show();
  delay(20);
  leds[3] = CRGB (255, 255, 225);
  FastLED.show();
  delay(20);
  leds[4] = CRGB (255,255,225);
  FastLED.show();
  delay(20);
  leds[5] = CRGB (255, 255,225);
  FastLED.show();
  delay(20);
  leds[14] = CRGB (255, 255,225);
  FastLED.show();
  delay(20);
  leds[15] = CRGB (255, 255,225);
  FastLED.show();
  delay(20);
  leds[16] = CRGB (255,255,225);
  FastLED.show();
  delay(20);
  leds[17] = CRGB (255, 255, 225);
  FastLED.show();
  delay(20);
  leds[18] = CRGB (255, 255, 225);
  FastLED.show();
  delay(20);
  leds[11] = CRGB (255, 255, 225);
  FastLED.show();
  delay(20);
  leds[8] = CRGB (255, 255,225);
  FastLED.show();
  delay(20);
  leds[7] = CRGB (255,255, 225);
  FastLED.show();
  delay(20);
  leds[6] = CRGB (255,255, 225);
  FastLED.show();
  delay(20);
  leds[13] = CRGB (255,255, 225);
  FastLED.show();
  delay(20);
  leds[12] = CRGB (255,255, 225);
  FastLED.show();
  delay(20);
}


void red(){
  leds[18] = CRGB (255,0,0);
  FastLED.show();
  delay(50);
  leds[16] = CRGB (255,0,0);
  leds[17] = CRGB (255,0,0);
  leds[11] = CRGB (255,0,0);
  FastLED.show();
  delay(50);
  leds[15] = CRGB (255,0,0);
  leds[14] = CRGB (255,0,0);
  leds[13] = CRGB (255,0,0);
  leds[12] = CRGB (255,0,0);
  FastLED.show();
  delay(50);
  leds[4] = CRGB (255,0,0);
  leds[5] = CRGB (255,0,0);
  leds[7] = CRGB (255,0,0);
  leds[6] = CRGB (255,0,0);
  leds[8] = CRGB (255,0,0);
  FastLED.show();
  delay(50);
  leds[1] = CRGB (255,0,0);
  leds[3] = CRGB (255,0,0);
  leds[2] = CRGB (255,0,0);
  FastLED.show();

}


void green(){
  leds[18] = CRGB (0,255,0);
  FastLED.show();
  delay(50);
  leds[16] = CRGB (0,255,0);
  leds[17] = CRGB (0,255,0);
  leds[11] = CRGB (0,255,0);
  FastLED.show();
  delay(50);
  leds[15] = CRGB (0,255,0);
  leds[14] = CRGB (0,255,0);
  leds[13] = CRGB (0,255,0);
  leds[12] = CRGB (0,255,0);
  FastLED.show();
  delay(50);
  leds[4] = CRGB (0,255,0);
  leds[5] = CRGB (0,255,0);
  leds[7] = CRGB (0,255,0);
  leds[6] = CRGB (0,255,0);
  leds[8] = CRGB (0,255,0);
  FastLED.show();
  delay(50);
  leds[1] = CRGB (0,255,0);
  leds[3] = CRGB (0,255,0);
  leds[2] = CRGB (0,255,0);
  FastLED.show();

}


void blue(){
  leds[18] = CRGB (0, 0,255);
  FastLED.show();
  delay(50);
  leds[16] = CRGB (0, 0,255);
  leds[17] = CRGB (0, 0,255);
  leds[11] = CRGB (0, 0,255);
  FastLED.show();
  delay(50);
  leds[15] = CRGB (0, 0,255);
  leds[14] = CRGB (0,0,255);
  leds[13] = CRGB (0,0,255);
  leds[12] = CRGB (0,0,255);
  FastLED.show();
  delay(50);
  leds[4] = CRGB (0,0,255);
  leds[5] = CRGB (0,0,255);
  leds[7] = CRGB (0,0,255);
  leds[6] = CRGB (0,0,255);
  leds[8] = CRGB (0,0,255);
  FastLED.show();
  delay(50);
  leds[1] = CRGB (0,0,255);
  leds[3] = CRGB (0,0,255);
  leds[2] = CRGB (0,0,255);
  FastLED.show();

}


void intro(){
  leds[15] = CRGB (255,90,0);
  leds[16] = CRGB (255,90,0);
  leds[17] = CRGB (255,90,0);
  leds[18] = CRGB (255,90,0);
  FastLED.show();
  delay(50);
  leds[14] = CRGB (255,50,0);
  leds[13] = CRGB (255,50,0);
  leds[12] = CRGB (255,50,0);
  leds[11] = CRGB (255,50,0);
  FastLED.show();
  delay(50);
  leds[5] = CRGB (255,90,0);
  leds[6] = CRGB (255,90,0);
  leds[7] = CRGB (255,90,0);
  leds[8] = CRGB (255,90,0);
  FastLED.show();
  delay(50);
  leds[4] = CRGB (255,50,0);
  leds[3] = CRGB (255,50,0);
  leds[2] = CRGB (255,50,0);
  leds[1] = CRGB (255,50,0);
  FastLED.show();
}


void goblack(){
  leds[15] = CRGB (0, 0,0);
  leds[14] = CRGB (0, 0,0);
  leds[5] = CRGB (0, 0,0);
  leds[4] = CRGB (0, 0,0);
  leds[16] = CRGB (0, 0,0);
  leds[13] = CRGB (0,0,0);
  leds[6] = CRGB (0,0,0);
  leds[3] = CRGB (0,0,0);
  leds[17] = CRGB (0,0,0);
  leds[12] = CRGB (0,0,0);
  leds[7] = CRGB (0,0,0);
  leds[2] = CRGB (0,0,0);
  leds[18] = CRGB (0,0,0);
  leds[11] = CRGB (0,0,0);
  leds[8] = CRGB (0,0,0);
  leds[1] = CRGB (0,0,0);
  FastLED.show();
  delay(200);
}

void flag(){
  leds[15] = CRGB (255,60,0);
  leds[14] = CRGB (255,60,0);
  leds[5] = CRGB (255,60,0);
  leds[4] = CRGB (255,60,0);
  FastLED.show();
  delay(50);
  leds[16] = CRGB (255,255,150);
  leds[13] = CRGB (255,255,150);
  leds[6] = CRGB (255,255,150);
  leds[3] = CRGB (255,255,150);
  FastLED.show();
  delay(50);
  leds[17] = CRGB (255,255,150);
  leds[12] = CRGB (255,255,150);
  leds[7] = CRGB (255,255,150);
  leds[2] = CRGB (255,255,150);
  FastLED.show();
  delay(50);
  leds[18] = CRGB (0,255,0);
  leds[11] = CRGB (0,255,0);
  leds[8] = CRGB (0,255,0);
  leds[1] = CRGB (0,255,0);
  FastLED.show();
}

void cool(){
  leds[13] = CRGB (0,150,255);
  leds[12] = CRGB (255,0,150);
  leds[6] = CRGB (150,255,0);
  leds[7] = CRGB (255,255,0);
  FastLED.show();
  delay(50);
  leds[16] = CRGB (0,150,255);
  leds[17] = CRGB (255,0,150);
  leds[14] = CRGB (0,150,255);
  leds[5] = CRGB (150,255,0);
  leds[3] = CRGB (150,255,0);
  leds[2] = CRGB (255,255,0);
  leds[11] = CRGB (255,0,150);
  leds[8] = CRGB (255,255,0);
  FastLED.show();
  delay(50);
  leds[15] = CRGB (0,150,255);
  leds[4] = CRGB (150,255,0);
  leds[18] = CRGB (255,0,150);
  leds[1] = CRGB (255,255,0);
  FastLED.show();
}
