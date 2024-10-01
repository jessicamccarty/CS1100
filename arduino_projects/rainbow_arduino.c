// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library
// Group Members: Jessica McCarty and Terrell Smith

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 16 // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

// Define an array of colors (R, G, B)
uint32_t colors[] = {
  pixels.Color(255, 0, 0),   // Red
  pixels.Color(0, 255, 0),   // Green
  pixels.Color(0, 0, 255),   // Blue
  pixels.Color(255, 255, 0), // Yellow
  pixels.Color(0, 255, 255), // Cyan
  pixels.Color(255, 0, 255), // Magenta
};

const int numColors = sizeof(colors) / sizeof(colors[0]); // Number of colors

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  for(int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    // Set each pixel to a color from the colors array
    pixels.setPixelColor(i, colors[i % numColors]);

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
}
