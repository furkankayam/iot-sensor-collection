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

  // Create a new file and write data to it
  File myFile = SD.open("furkan.txt", FILE_WRITE);
  
  // If the file is successfully opened, write data to it
  if (myFile) {
    Serial.println("New file created and writing...");
    myFile.println("This is a text written to a new file."); // Write to the file
    myFile.close(); // Close the file
    Serial.println("Writing process completed.");
  } else {
    // If the file cannot be opened, print an error message
    Serial.println("Failed to create the file!");
  }

  // Reopen the file and print its contents to the serial port
  myFile = SD.open("furkan.txt");
  if (myFile) {
    Serial.println("Contents of furkan.txt:");
    
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