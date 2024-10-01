/***
 * Group Members: 
 * Notes:
 * Color have been changed o
 */

#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

Servo doorServo;
// Pin
#define LED_PIN 6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 5

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Pin
#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 3

// Create instances
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup()
{
    // Initialize serial communication
    Serial.begin(9600);
    digitalWrite(B_PIN, LOW);

    pinMode(B_PIN, OUTPUT);
    mfrc522.PCD_Init(); // Initialize the RFID reader
                        // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
                        // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
#endif
    // END of Trinket-specific code.

    strip.begin();               // INITIALIZE NeoPixel strip object (REQUIRED)
    doorServo.attach(SERVO_PIN); // Attach the servo motor to the pin
    strip.show();                // Turn OFF all pixels ASAP
    SPI.begin();
    strip.setBrightness(50);     // Set BRIGHTNESS to about 1/5 (max = 255)
   
    // Set initial positions and colors
    doorServo.write(0); // Initial position (door closed)

    Serial.println("RFID Door System Initialized. Waiting for RFID card...");
    digitalWrite(A_PIN, LOW);
}

void loop()
{
    // Check if an RFID card is present
    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return;
    }

    Serial.print("Card UID: ");
    String content = "";
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    Serial.println(content);

    // Read the RFID card
    if (!mfrc522.PICC_ReadCardSerial())
    {
        return;
    }

    // Compare the UID with a known UID
    if (content.substring(1) == "04 B3 77 4A B3 34 81")
    {
        Serial.println("Access Granted");
        doorServo.write(90); 
        // Open the door
                             // Hue of first pixel runs 5 complete loops through the color wheel.
        // Color wheel has a range of 65536 but it's OK if we roll over, so
        // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
        // means we'll make 5*65536/256 = 1280 passes through this loop:
        for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256)
        {
            // strip.rainbow() can take a single argument (first pixel hue) or
            // optionally a few extras: number of rainbow repetitions (default 1),
            // saturation and value (brightness) (both 0-255, similar to the
            // ColorHSV() function, default 255), and a true/false flag for whether
            // to apply gamma correction to provide 'truer' colors (default true).
            strip.rainbow(firstPixelHue);
            // Above line is equivalent to:
            // strip.rainbow(firstPixelHue, 1, 255, 255, true);
            strip.show(); // Update strip with new contents
            delay(10);    // Pause for a moment
        }
        delay(5000);        // Keep the door open for 5 seconds
        doorServo.write(0); // Close the door
    }
    else
    {
        Serial.println("Access Granted");
        // Red light for failure
        for (int i = 0; i < strip.numPixels(); i++)
        {                                                                  // For each pixel in strip...
            strip.setPixelColor(i, colorWipe(strip.Color(255, 0, 0), 50)); // Red   //  Set pixel's color (in RAM)
            strip.show();                                                  //  Update strip to match
            delay(2000);                                                   //  Pause for a moment
        }

        // Halt the RFID reader temporarily
        mfrc522.PICC_HaltA();
    }
}
