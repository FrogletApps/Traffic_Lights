int buttonstate = 0;
int count = 0;
int count2 = 3;
int segmentcount[4] = {6,7,8,9};

void setup() {
  // put your setup code here, to run once:
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);

pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);

pinMode(12, INPUT);
pinMode(13, OUTPUT);

//for the main traffic lights
#define RedLED 0
#define YellowLED 1
#define GreenLED 2

//for the buzzer
#define Buzzer 3

//for the pedestrian green/red man
#define Red2LED 4
#define Green2LED 5

//7 segment display stuff - I only used the button four segments
#define bottomright 6
#define bottommid 7
#define bottomleft 8
#define midmid 9

//button to indicate someone is waiting
#define Button 12

//a "wait" light - this can just be on the board, although mine is also connected to the bottom right dot on the 7 segment display
#define LED 13

//test that everything is working - quickly turn all LEDs on and off and beep twice
blinky();
//beeps once to indicate this is done, and the program has started
beep250();
}

void loop() {
  //This is the main code, and will be repeated forever

  //make sure that all LEDs are off
reset();

//if the button has been pressed, do the traffic light sequence, if not then check button again
//button state low means the button has been pressed

buttonstate = digitalRead(Button);
 if (buttonstate == LOW) {
  digitalWrite(LED,HIGH);
  digitalWrite(Red2LED,LOW);
  digitalWrite(Green2LED,HIGH);
  trafficlight();

 }
  else {
    digitalWrite(GreenLED,HIGH);
    digitalWrite(Red2LED,HIGH);
    digitalWrite(Green2LED,LOW);
    digitalWrite(LED,LOW);
 }
}

//below are subroutines


//this is the setup, to make sure everything is working
void blinky() {
set();
  delay (500);
reset();
  delay (1000);
}

//turns all the LEDs off
void reset(){
  digitalWrite(RedLED,LOW);
  digitalWrite(YellowLED,LOW);
  digitalWrite(GreenLED,LOW);
  digitalWrite(Green2LED,LOW);
  digitalWrite(Red2LED,LOW);
  segmentoff();
}

//turns all the LEDs on and beeps the buzzer twice
void set(){
  digitalWrite(RedLED,HIGH);
  digitalWrite(YellowLED, HIGH);
  digitalWrite(GreenLED,HIGH);
  digitalWrite(Red2LED,HIGH);
  digitalWrite(Green2LED,HIGH);
  segmenton();
  beep250();
  beep250();
}

//turns all the segments on the 7 segment display on
void segmenton(){
  digitalWrite(bottomright,HIGH);
  digitalWrite(bottommid,HIGH);
  digitalWrite(bottomleft,HIGH);
  digitalWrite(midmid,HIGH);
}


//turns all the segments on the 7 segment display off
void segmentoff(){
  digitalWrite(bottomright,LOW);
  digitalWrite(bottommid,LOW);
  digitalWrite(bottomleft,LOW);
  digitalWrite(midmid,LOW);
}

//this makes the buzzer beep - it takes 250ms to complete
void beep250(){
  tone(Buzzer,2500,100);
  delay (150);
}

//this is the traffic light sequence - I'm not saying what all this does as it'll take too long, but in the middle is the control for the buzzer, this also controls the 7 segment display.
void trafficlight(){
  reset();
  digitalWrite(GreenLED,HIGH);
  digitalWrite(Red2LED,HIGH);
  delay (4000);
  digitalWrite (GreenLED,LOW);
  digitalWrite(YellowLED,HIGH);
  delay (2000);
  digitalWrite(YellowLED,LOW);
  digitalWrite (RedLED,HIGH);
  delay (1000);
  digitalWrite (Red2LED, LOW);
  digitalWrite (Green2LED,HIGH);
  digitalWrite (LED, LOW);
  count = 0;
  count2 = 4;
    while(count<13){
      count++;
      beep250();
        if (count%3 == 0){
        count2--;
        digitalWrite(segmentcount[count2],HIGH);
        }
    }
  delay (500);  
  digitalWrite(Green2LED,LOW);
  digitalWrite(RedLED,HIGH);
  digitalWrite (Red2LED,HIGH);
  delay(2000);
  segmentoff();
  digitalWrite(YellowLED,HIGH);
  delay(2000);
  digitalWrite(YellowLED,LOW);
  digitalWrite(RedLED,LOW);
  digitalWrite(GreenLED,HIGH); 
}
