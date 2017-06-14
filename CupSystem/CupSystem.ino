#include "Sensor.h"
#include <mcp_can.h>
#include <SPI.h>
MCP_CAN CAN0(10);
Sensor* sensor;
int led = 7;
bool isCup = false;
void setup() {
  Serial.begin(9600);
  sensor = new Sensor(A0);
  pinMode(led,OUTPUT);
  // put your setup code here, to run once:
  // Initialize MCP2515 running at 16MHz with a baudrate of 100kb/s and the masks and filters disabled.
  if (CAN0.begin(MCP_ANY, CAN_100KBPS, MCP_16MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");
  CAN0.setMode(MCP_NORMAL);
}

void loop() {
  digitalWrite(led,isCup);
  // Serial.println();
  if (sensor->Read())
  {
    if (!isCup)
    {
      isCup = true;
       Serial.println("cup placed");
       sendStatus(0x01);
       
    }
  }
  else
  {
    if (isCup)
    {
       Serial.println("Cup removed");
      isCup = false;
      sendStatus(0x00);
    }
  }
  delay(100);
}
void sendStatus(uint8_t cupStatus)
{
  byte data[8] = {cupStatus};
  byte sndStat = CAN0.sendMsgBuf(0x40, 0, 1, data);
  if (sndStat == CAN_OK) {
    Serial.println("Message Sent Successfully!");
  } else {
    Serial.println("Error Sending Message...");
  }
}
