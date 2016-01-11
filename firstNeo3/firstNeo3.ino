// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            5
#define PIN2           6
#define ROT            A0
#define SWI            4
/*
#define BUTb           7
#define BUTr           4
#define BUTg           2
   int color = 0;
*/


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      3

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
   pinMode(ROT, INPUT);
   pinMode(SWI, INPUT);
   
/*
   pinMode(BUTb, INPUT);
   pinMode(BUTr, INPUT);
   pinMode(BUTg, INPUT);
*/

  
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
    int pot = analogRead(ROT);
    int LEDn = map(pot,0,1024,40,255);
    int LEDm = map(pot,0,770,0,40);
    
  /*  if(digitalRead(SWI) == HIGH){
      for (int i = 0; i < 3; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 255, 255));
      }
    }
    */
        pixels.setPixelColor(1, pixels.Color(255, 255, 255));
        pixels.setPixelColor(2, pixels.Color(255, 255, 255));


    if(digitalRead(SWI) == LOW){
      for (int i = 0; i < 3; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }
/*
    if(digitalRead(BUTb) == HIGH){
      color = 1;
    }
    if(digitalRead(BUTr) == HIGH){
      color = 2;
    }
    if(digitalRead(BUTg) == HIGH){
      color = 3;
    }
    
    if(color == 1){
      for (int i = 0; i < 10; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, LEDn));
      }
    }
    if(color == 2){
      for (int i = 0; i < 10; i++) {
        pixels.setPixelColor(i, pixels.Color(LEDn, 0, 0));
      }
    }
    if(color == 3){
      for (int i = 0; i < LEDm; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 155, 0));
      }
      for (int i = (LEDm + 1); i < 40; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
    }

   pixels2.setPixelColor(1, pixels2.Color(0, 155, 0));
    pixels2.setPixelColor(2, pixels2.Color(0, 155, 0));
*/
    pixels.show();
   

   Serial.begin(9600);  
   Serial.print(pot);
   Serial.print("      ");
   Serial.println(LEDn);
   //Serial.println(color);
   delay(500);


/*
  for (int i = 0; i < NUMPIXELS; i++) {

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0, 155, 0)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
*/

}
