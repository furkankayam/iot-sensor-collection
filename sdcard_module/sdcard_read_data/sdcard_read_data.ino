#include <SPI.h>
#include <SD.h>

const int chipSelect = 53; // SD card module's CS pin

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize the SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Initialization failed!");
    return;
  }
  Serial.println("Initialization completed.");

  // Open the file
  File myFile = SD.open("test.txt");
  if (myFile) {
    Serial.print("Contents of test.txt: ");

    // Read the file line by line and print to the serial port
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    
    // Close the file
    myFile.close();
  } else {
    // If the file cannot be opened, print an error message
    Serial.println("Failed to open the file!");
  }
}

void loop() {
  // The loop function is left empty
}