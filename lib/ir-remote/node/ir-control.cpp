#include "ir-control.h"

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.

IRControl::IRControl(const char * name,
  const char * id, Device * device): Node(name, id, device) {}

bool IRControl::Init(Homie * homie) {
  Node::Init(homie);
  irsend.begin();

  return true;
}

void IRControl::HandleCurrentState() {
  if (properties_.find("onoffbutton")->second->HasNewValue()) {
      irsend.sendNEC(ONOFF_NEC);

      properties_.find("onoffbutton")->second->SetValue("false");
      properties_.find("onoffbutton")->second->SetHasNewValue(false);
  }
  if (properties_.find("volumeup")->second->HasNewValue()) {
      irsend.sendNEC(VOLUME_UP_NEC);

      properties_.find("volumeup")->second->SetValue("false");
      properties_.find("volumeup")->second->SetHasNewValue(false);
  }
  if (properties_.find("volumedown")->second->HasNewValue()) {
      irsend.sendNEC(VOLUME_DOWN_NEC);

      properties_.find("volumedown")->second->SetValue("false");
      properties_.find("volumedown")->second->SetHasNewValue(false);
  }
  if (properties_.find("channel1")->second->HasNewValue()) {
      irsend.sendNEC(CHANNEL1_NEC);

      properties_.find("channel1")->second->SetValue("false");
      properties_.find("channel1")->second->SetHasNewValue(false);
  }

  if (properties_.find("channel2")->second->HasNewValue()) {
      irsend.sendNEC(CHANNEL2_NEC);

      properties_.find("channel2")->second->SetValue("false");
      properties_.find("channel2")->second->SetHasNewValue(false);
  }
}
