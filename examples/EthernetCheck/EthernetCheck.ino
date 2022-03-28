#include <SPI.h>
#include <Ethernet.h>

EthernetClient client;

bool ETHERNET_LINK = false;
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};


void checkEthernetStatus() {


  auto link = Ethernet.linkStatus();

  switch (link) {
    case Unknown:
      ETHERNET_LINK = false;
      Serial.println("Unknown");
      break;
    case LinkON:
      ETHERNET_LINK = true;
      //digitalWrite(LED_LINK, LEDON);
      Serial.println("LINK ON");
      break;
    case LinkOFF:
      ETHERNET_LINK = false;
      Serial.println("LINK OFF");
      break;
  }

}

void setup ( void ) {
  Serial.begin(115200);
  
  Ethernet.begin(mac);    // begin with get DHCP
}

void loop() {
  checkEthernetStatus();
  delay(1000);
}
