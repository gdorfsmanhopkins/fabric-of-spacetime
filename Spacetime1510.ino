#include <Servo.h>
#include <Adafruit_NeoPixel.h>

//set the sensor pin
//NOTE: THIS MUST BE AN INTERRUPT COMPATIBLE PIN
int sensor = 2;

//define motor pins
int motor1 = 34;
int motor2 = 24;
int motor3 = 26;
int motor4 = 40;
int motor5 = 30;
int motor6 = 53;

//Define the high and low points of each motor
int m1high = 20;
int m1low = 180;

int m2high = 180;
int m2low = 30;

int m3high = 180;
int m3low = 0;

int m4high = 180;
int m4low = 0;

int m5high = 0;
int m5low = 180;

int m6high = 180;
int m6low =40;

//Define the servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

//Define the neopixels
int leds = 10;
int numberOfPixels = 264;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numberOfPixels, leds, NEO_GRB + NEO_KHZ800);

void setup() {
  //intiate the sensor pin as an interrupt
  pinMode(sensor,INPUT);
  attachInterrupt(digitalPinToInterrupt(sensor),trigger,RISING);
  
  //initialize the neopixels
  pixels.begin();

  //set them blue
  for (int j=0;j<numberOfPixels;j++){
    pixels.setPixelColor(j,pixels.Color(0,0,0));
  }
  pixels.show();
  
  //attach the motors
  servo1.attach(motor1);
  servo2.attach(motor2);
  servo3.attach(motor3);
  servo4.attach(motor4);
  servo5.attach(motor5);
  servo6.attach(motor6);

  //send the motors to their initial positions

  servo1.write(m1low);  
  servo2.write(m2low);  
  servo3.write(m3low);  
  servo4.write(m4low);  
  servo5.write(m5low);  
  servo6.write(m6low);  


  Serial.begin(9600);
}

void idle() {

  for(int i = 0;i<100;i++){
    //set the next neopixel color
    for(int j = 0;j<numberOfPixels;j++){
      pixels.setPixelColor(j,pixels.Color(int(2.5*i),0,255-int(2.5*i)));
    }
    pixels.show();
    servo1.write(m1low + i*(m1high-m1low)/99);
    servo2.write(m2low + i*(m2high-m2low)/99);
    servo3.write(m3low + i*(m3high-m3low)/99);
    servo4.write(m4low + i*(m4high-m4low)/99);
    servo5.write(m5low + i*(m5high-m5low)/99);
    servo6.write(m6low + i*(m6high-m6low)/99);
    Serial.println("in");
    delay(20);
  }
  for(int i = 99; i>-1; i--){    
    for(int j = 0;j<numberOfPixels;j++){
      pixels.setPixelColor(j,pixels.Color(int(2.5*i),0,255-int(2.5*i)));
    }
    pixels.show();
    servo1.write(m1low + i*(m1high-m1low)/99);
    servo2.write(m2low + i*(m2high-m2low)/99);
    servo3.write(m3low + i*(m3high-m3low)/99);
    servo4.write(m4low + i*(m4high-m4low)/99);
    servo5.write(m5low + i*(m5high-m5low)/99);
    servo6.write(m6low + i*(m6high-m6low)/99);
    Serial.println("out");
    delay(20);
  }
}

void motorSpaz(int a,int b) {
  if(a==0){
    if(b==0){
      servo1.write(m1low);
    }
    else{
      servo1.write(m1high);
    }
  }  
  if(a==1){
    if(b==0){
      servo2.write(m2low);
    }
    else{
      servo2.write(m2high);
    }
  }
  if(a==2){
    if(b==0){
      servo3.write(m3low);
    }
    else{
      servo3.write(m3high);
    }
  }  
  if(a==3){
    if(b==0){
      servo4.write(m4low);
    }
    else{
      servo4.write(m4high);
    }
  }  
  if(a==4){
    if(b==0){
      servo5.write(m5low);
    }
    else{
      servo5.write(m5high);
    }
  }  
  if(a==5){
    if(b==0){
      servo6.write(m6low);
    }
    else{
      servo6.write(m6high);
    }
  }
}

void spazAll(){
  for (int timer=0;timer<50;timer++){
    for (int j = 0;j<numberOfPixels;j++){
      pixels.setPixelColor(j,pixels.Color(random(256),random(256),random(256)));
    }
    pixels.show();
    int a = random(6);
    int b = random(2);
    motorSpaz(a,b);
    delayMicroseconds(5000);
  }
}
void spazNoRed(){
  for (int timer=0;timer<50;timer++){
    for (int j = 0;j<numberOfPixels;j++){
      pixels.setPixelColor(j,pixels.Color(0,random(256),random(256)));
    }
    pixels.show();
    int a = random(6);
    int b = random(2);
    motorSpaz(a,b);
    delayMicroseconds(5000);
  }
}
void spazNoGreen(){
  for (int timer=0;timer<50;timer++){
    for (int j = 0;j<numberOfPixels;j++){
      pixels.setPixelColor(j,pixels.Color(random(256),0,random(256)));
    }
    pixels.show();
    int a = random(6);
    int b = random(2);
    motorSpaz(a,b);
    delayMicroseconds(5000);
  }
}
void spazNoBlue(){
  for (int timer=0;timer<50;timer++){
    for (int j = 0;j<numberOfPixels;j++){
      pixels.setPixelColor(j,pixels.Color(random(256),random(256),0));
    }
    pixels.show();
    int a = random(6);
    int b = random(2);
    motorSpaz(a,b);
    delayMicroseconds(5000);
  }
}

void spaz(){
  int colorChoice = random(4);
  if (colorChoice==0){
    spazAll();
  }
  if (colorChoice==1){
    spazNoRed();
  }
  if (colorChoice==2){
    spazNoGreen();
  }
  if (colorChoice==3){
    spazNoBlue();
  }
}

void breathe(){
  //set the pixels blue
  for (int j=0;j<numberOfPixels;j++){
    pixels.setPixelColor(j,pixels.Color(0,0,0));
  }
  pixels.show();

  //send the motors to their initial positions

  servo1.write(m1low);  
  servo2.write(m2low);  
  servo3.write(m3low);  
  servo4.write(m4low);  
  servo5.write(m5low);  
  servo6.write(m6low);  

  delayMicroseconds(10000);
  
  servo1.write(m1high);
  for (int i = 0; i < 44; i++) {
    pixels.setPixelColor(numberOfPixels - i, pixels.Color(i, 150 + i, 255 - i));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo2.write(m2high);
  for (int i = 44; i < 88; i++) {
    pixels.setPixelColor(numberOfPixels - i, pixels.Color(i, 150 + i, 255 - i));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo3.write(m3high);
  for (int i = 88; i < 132; i++) {
    pixels.setPixelColor(numberOfPixels - i, pixels.Color(i, 150 + i, 255 - i));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo4.write(m4high);
  for (int i = 132; i < 176; i++) {
    pixels.setPixelColor(numberOfPixels - i, pixels.Color(i, 150 + i, 255 - i));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo5.write(m5high);
  for (int i = 176; i < 220; i++) {
    pixels.setPixelColor(numberOfPixels - i, pixels.Color(i, 150 + i, 255 - i));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo6.write(m6high);
  for (int i = 220; i < 264; i++) {
    pixels.setPixelColor(numberOfPixels - i, pixels.Color(i, 150 + i, 255 - i));
    pixels.show();
  }
  delayMicroseconds(1000000);
  servo1.write(m1low);
  for (int i = 0; i < 44; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo2.write(m2low);
  for (int i = 44; i < 88; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo3.write(m3low);
  for (int i = 88; i < 132; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo4.write(m4low);
  for (int i = 132; i < 176; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delayMicroseconds(5000);
  }
  servo5.write(m5low);
  for (int i = 176; i < 220; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delayMicroseconds(5000);
    }
  servo6.write(m6low);
  for (int i = 220; i < 264; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delayMicroseconds(5000);
  }
}

void trigger(){
  int which = random(2);
  if(which==1){
    spaz();
  }
  else{
    breathe();
  }
}

void loop() {
  idle();
}
