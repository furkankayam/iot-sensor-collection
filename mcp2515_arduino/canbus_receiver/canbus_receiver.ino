#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;

MCP2515 mcp2515(10);

void setup() {
  Serial.begin(9600);
  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop() {
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    Serial.print("ID: 0x");
    Serial.println(canMsg.can_id, HEX);  // CAN ID'yi yazdır

    Serial.print("Data: ");
    for (int i = 0; i < canMsg.can_dlc; i++) { // Tüm data byte'larını yazdır
      Serial.print(canMsg.data[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
}