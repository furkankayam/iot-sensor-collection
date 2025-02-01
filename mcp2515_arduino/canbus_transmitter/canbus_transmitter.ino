#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;

MCP2515 mcp2515(10);

unsigned int counter = 0;

void setup() {
  while (!Serial);
  Serial.begin(9600);

  SPI.begin();

  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop() {
  counter++;

  canMsg.can_id = 0x036;
  canMsg.can_dlc = 8;

  // Sayacı 8 byte'a sığdırmak için farklı yöntemler kullanabilirsiniz.
  // Örneğin, en düşük 2 byte'ı kullanabilirsiniz:
  canMsg.data[0] = lowByte(counter);
  canMsg.data[1] = highByte(counter);
  canMsg.data[2] = 0x00;
  canMsg.data[3] = 0x00;
  canMsg.data[4] = 0x00;
  canMsg.data[5] = 0x00;
  canMsg.data[6] = 0x00;
  canMsg.data[7] = 0x00;


  mcp2515.sendMessage(&canMsg);

  Serial.print("Gönderilen: ");
  Serial.println(counter);

  delay(1000);
}