/*
 * This project is a clicker, using a small oled screen for displaying n0 of clicks.
 * Using a single MX button you can click for counter++, hold for 3+ seconds for saving counter to EEPROM or hold 15+ seconds for EEPROM reset
 * Board : Arduino Nano
 * Oled : 0.91' Oled I2C 128x32 pixel (4pin)
 * Lipo : 400mah 3,7v 1 cell
 * Lipo Charger + Step Up 5v Module
 * Wiring :
 *          A0 -> Lipo+                     reading battery life
 *          GND -> Lipo-                    reding battery life
 *          D2 -> Button+                   button for clicks
 *          D2 -> 10k Restistor -> GND      resistor for debounce
 *          Vin -> Charge Modude OUT+
 *          GND -> Charge Modure OUT-
 *          Charge Module BAT+ -> Lipo+
 *          Charge Module BAT- -> Lipo+
 *          Oled 5V -> Arduino 5V or Charge Module OUT+
 *          Oled GND -> GND or Charge Module OUT-
 *          Oled SDA -> A4
 *          Oled SCL -> A5
 */
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROMex.h>

#define SCREEN_WIDTH 128   // OLED display width, in pixels
#define SCREEN_HEIGHT 32   // OLED display height, in pixels
#define OLED_RESET     4   // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define NUMFLAKES     10   // Number of snowflakes in the animation example
#define LOGO_HEIGHT   32   // Set Oled screen boundries
#define LOGO_WIDTH    128  // Set Oled screen boundries

#define lipoPin A0         // Set A0 as the lipo Voltage read pin
float lipoV = 0;           // the variable for lipo Voltage readings

#define Battery_BMPWIDTH  14  //Bitmap for displaying Battery 75% - 100%
#define Battery_BMPHEIGHT  25
const unsigned char bitmap_BatteryFull[] PROGMEM = {
  B00000000, B00000000, // ................
  B00001111, B11000000, // ....######......
  B00001111, B11000000, // ....######......
  B01111111, B11111000, // .############...
  B01000000, B00001000, // .#..........#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01000000, B00001000, // .#..........#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01000000, B00001000, // .#..........#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01000000, B00001000, // .#..........#...
  B01111111, B11111000, // .############...
  B00000000, B00000000 // ................
};

#define Battery_BMPWIDTH  14  //Bitmap for displaying Battery 50%
#define Battery_BMPHEIGHT  25
const unsigned char bitmap_BatteryMid[] PROGMEM = {
  B00000000, B00000000, // ................
  B00001111, B11000000, // ....######......
  B00001111, B11000000, // ....######......
  B01111111, B11111000, // .############...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01000000, B00001000, // .#..........#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01000000, B00001000, // .#..........#...
  B01111111, B11111000, // .############...
  B00000000, B00000000 // ................
};

#define Battery_BMPWIDTH  14  //Bitmap for displaying Battery 25%
#define Battery_BMPHEIGHT  25
const unsigned char bitmap_BatteryLow[] PROGMEM = {
  B00000000, B00000000, // ................
  B00001111, B11000000, // ....######......
  B00001111, B11000000, // ....######......
  B01111111, B11111000, // .############...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01011111, B11101000, // .#.########.#...
  B01000000, B00001000, // .#..........#...
  B01111111, B11111000, // .############...
  B00000000, B00000000 // ................
};

#define Battery_BMPWIDTH  14  //Bitmap for displaying Battery 0%
#define Battery_BMPHEIGHT  25
const unsigned char bitmap_BatteryEmpty[] PROGMEM = {
  B00000000, B00000000, // ................
  B00001111, B11000000, // ....######......
  B00001111, B11000000, // ....######......
  B01111111, B11111000, // .############...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01000000, B00001000, // .#..........#...
  B01111111, B11111000, // .############...
  B00000000, B00000000 // ................
};


const int  buttonPin = 2;           // the pin that the pushbutton is attached to
const int LONG_PRESS_TIME  = 3000;  // set the short press duration for save = 3s
const int RESET_PRESS_TIME = 15000; // set the long press duration for erase = 15s

long delayCounter = 0;        // temp counter for saving the counter when saving
long buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;          // current state of the button
int lastButtonState = 0;      // previous state of the button

unsigned long pressedTime  = 0; // temp for saving the time ( milis() ) when button is pressed 
unsigned long releasedTime = 0; // temp for saving the time ( milis() ) when button is released 
//unsigned long looptime = 0;
//unsigned long duration = 0;

int bounds;             // varieble for Oled Screen Padding
int batteryPercentage;  // the voltage of the Lipo mapped in 0%, 25%, 50%, 75%, 100% 

void setup() {
  buttonPushCounter = EEPROM.readLong(0);   // read the counter from the first address of the EEPROM (0)
  pinMode(lipoPin, INPUT);                  // set A0 as an INPUT pin
  pinMode(13, OUTPUT);                      // set 13 (on-board led) as an OUTPUT pin
  pinMode(buttonPin, HIGH);                 // set the initial state of the button pin (2) as HIGH
  Serial.begin(9600);                       // baud for serial monitor
  Serial.println(buttonPushCounter);        // print the counter for debuging

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);                                       // Don't proceed, loop forever
  }
  display.clearDisplay();   // oled function for clearing display
  display.display();        // oled function to proceed on doing the previous commands
  delay(500);               // small delay on startup
}

void loop() {

  batteryPercentage = checkBattery(lipoPin , lipoV);      // call battery function to read A0 and return % value 
  bounds = cursorbounds(buttonPushCounter);               // call bounds function to return the cursor value for Oled Screen padding
  displayClicks(bounds, batteryPercentage, buttonState);  // call the display function to display Clicks and Battery on Oled Screen
  buttonState = digitalRead(buttonPin);                   // read the pushbutton input pin:

  if (buttonState != lastButtonState) {                   // if state (HiGH) is different from last state (LOW) 

    if (buttonState == HIGH) {          // if button is pressed
      pressedTime = millis();           // save the time when button is pressed
      Serial.println("HIGH");           //print for debuging
      
      //      while(duration >= 3000 && duration < 10000){
      //        looptime = millis();
      //        Serial.println(duration);
      //        duration = (pressedTime - looptime);
      //        displayReleaseForSave();
      //        break;
      //     }
      
    }
    else if (buttonState == LOW) {                      // if the current state is LOW then the button went from on to off:
      releasedTime = millis();                          // save the release time
      long pressDuration = releasedTime - pressedTime;  // calculate press duration for long or short clicks
      Serial.println("LOW");                            //print Low for debuging
      
      if ( pressDuration < LONG_PRESS_TIME ) {          //if press duration < 3s (short click)
        buttonPushCounter++;              // click counter is increased by 1
        if (buttonPushCounter > 9999) {   // display is set for 4x digits so if counter > 9999 reset it to 0
          displayEnd();                   // call a function to display that you reached the end
          buttonPushCounter = 0;          // set counter to 0 
        }
        //Serial.println("A short press is detected");  
        Serial.print("Clicks: ");
        Serial.println(buttonPushCounter);
      }
      else if ( pressDuration >= LONG_PRESS_TIME && pressDuration < RESET_PRESS_TIME ) { // if press duration >= 3s then Save
        EEPROM.writeLong(0, buttonPushCounter);                                          // save the counter on EEPROM address (0)
        Serial.println("Saving Data...");
        Serial.print("Saved counter ");
        Serial.print(buttonPushCounter);
        Serial.println(" on address 0");
        displaySaved();                                                                  // call a function to display "saving"
      }
      else if (pressDuration >= RESET_PRESS_TIME) { // if press duration >= 15s 
        displayErased();                            // call a function to display "erased"
        EEPROM.writeLong(0, 0);                     // set address (0) of EEPROM to 0
        digitalWrite(13, HIGH);                     // onboard led flash because Reasons
        buttonPushCounter = 0;                      // set counter back to 0
        Serial.println("Data is erased");
      }
    }
    delay(50);                                      //small delay to avoid bouncing and ghosting, button is Cherry MX Mechanical Switch
    lastButtonState = buttonState;                  // loop the states of the button
  }
}


void displayClicks(int width, int bat, int state) { // function to display clicks and battery image %
  display.clearDisplay();                           // clear display
  display.setTextSize(4);                           // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);              // set text to white
  display.setCursor(width, 2);                      // (0,0) is top-left corner, but i want the counter to be displayed sticked to the right
  if (bat == 100) {                                 // if state to display battery image
    display.drawBitmap(0, 5, bitmap_BatteryFull, 14, 25, WHITE);
    display.print(buttonPushCounter);
  }
  else if (bat == 75) {
    display.drawBitmap(0, 5, bitmap_BatteryFull, 14, 25, WHITE);
    display.print(buttonPushCounter);
  }
  else if (bat == 50) {
    display.drawBitmap(0, 5, bitmap_BatteryMid, 14, 25, WHITE);
    display.print(buttonPushCounter);
  }
  else if (bat == 25) {
    display.drawBitmap(0, 5, bitmap_BatteryLow, 14, 25, WHITE);
    display.print(buttonPushCounter);
  }
  while (bat == 0) {                                // if battery percentage is 0, enter a loop showing that bat is low, until bat is high
    int z;
    int pinTemp = A0;
    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(36, 12);     
    display.drawBitmap(0, 5, bitmap_BatteryEmpty, 14, 25, WHITE);
    display.println(F("Battery Low!"));
    display.display();
    delay(700);

    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(36, 12);     
    display.drawBitmap(0, 5, bitmap_BatteryEmpty, 14, 25, WHITE);
    display.println(F(" "));
    display.display();
    delay(700);
    z = analogRead(pinTemp);        // read battery voltage again to break loop
    z = map(z, 600, 950, 30, 42);
    Serial.println(z);
    if (z > 30) {
      break;
    }
  }
  display.display();
}

int cursorbounds(int x) {   //function with counter as an input, return the width of the cursor padding for display
  int clength;
  //if (x > 9999) {
  //clength = 8;
  //}
  if (x > 999) {
    clength = 32;
  } else if (x > 99) {
    clength = 56;
  } else if (x > 9) {
    clength = 76;
  } else if (x < 10) {
    clength = 104 ;
  }
  return clength;
}

void displaySaved() {                 // display Saving... (only for asthetics)
  for (int i = 0; i < 2; i++) {
    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(28, 12);     
    display.println(F("Saving Data"));
    display.display();
    delay(300);

    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(28, 12);     
    display.println(F("Saving Data."));
    display.display();
    delay(300);

    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(28, 12);     
    display.println(F("Saving Data.."));
    display.display();
    delay(300);

    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(28, 12);     
    display.println(F("Saving Data..."));
    display.display();
    delay(300);
  }
  display.clearDisplay();
  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(32, 12);     
  display.println(F("Data Saved!"));
  display.display();
  delay(1500);
}

void displayErased() {                    // display Erasing... (only for asthetics)
  for (int i = 0; i < 2; i++) {
    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(24, 12);     
    display.println(F("Erasing Data"));
    display.display();
    delay(300);

    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(24, 12);     
    display.println(F("Erasing Data."));
    display.display();
    delay(300);

    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(24, 12);     
    display.println(F("Erasing Data.."));
    display.display();
    delay(300);

    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(24, 12);     
    display.println(F("Erasing Data..."));
    display.display();
    delay(300);
  }
  display.clearDisplay();
  display.setTextSize(1);      
  display.setTextColor(SSD1306_WHITE); 
  display.setCursor(32, 12);     
  display.println(F("Data Erased!"));
  display.display();
  delay(1500);
}

//void displaySeconds(long t) {
//  display.clearDisplay();
//  display.setTextSize(4);      // Normal 1:1 pixel scale
//  display.setTextColor(SSD1306_WHITE); // Draw white text
//  display.setCursor(75, 2);     // Start at top-left corner
//  display.print(t / 1000 );
//  display.display();
//}

int checkBattery(int pin, float b) {          // funtion with pin A0 pin and Lipo V as input, maps and returns raw voltage reads to percentage
  int percentage;
  int voltage;
  b = analogRead(pin);
  //Serial.print("The A0 reads: ");
  //Serial.println(b);
  voltage = map(b, 600, 950, 30, 42);
  if (voltage >= 40) {
    percentage = 100;
  }
  else if (voltage > 38 && voltage < 40) {
    percentage = 75;
  }
  else if (voltage > 34 && voltage <= 38) {
    percentage = 50;
  }
  else if (b > 30 && voltage <= 34) {
    percentage = 25;
  }
  else if (voltage <= 30) {
    percentage = 0;
  }
  return percentage;
}

//int displayReleaseForSave() {
//  display.clearDisplay();
//  display.setTextSize(1);      // Normal 1:1 pixel scale
//  display.setTextColor(SSD1306_WHITE); // Draw white text
//  display.setCursor(20, 12);     // Start at top-left corner
//  display.print(F("Release for Save!"));
//  display.display();
//}
//int displayReleaseForErase() {
//  display.clearDisplay();
//  display.setTextSize(1);      // Normal 1:1 pixel scale
//  display.setTextColor(SSD1306_WHITE); // Draw white text
//  display.setCursor(16, 12);     // Start at top-left corner
//  display.print(F("Release for Clear!"));
//  display.display();
//}
 
void displayEnd() {                     //function to display "The end" (only for Asthetics)         
  for (int i = 0; i < 4; i++) {
    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(30, 12);     
    display.println(F("* The End *"));
    display.display();
    delay(700);

    display.clearDisplay();
    display.setTextSize(1);      
    display.setTextColor(SSD1306_WHITE); 
    display.setCursor(30, 12);     
    display.println(F("  The End  "));
    display.display();
    delay(700);
  }
}
