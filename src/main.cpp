#include "main.h"

Cloud2Smart smartcloud;

void setup() {
    IRControl *ircontrol = new IRControl("IR Control", "ir-control", smartcloud.GetDevice());

    Property *redButton = new Property("TV ON/OFF", "onoffbutton", ircontrol, SENSOR, true, false, "boolean");

    Property *volumeup = new Property("Volume +", "volumeup", ircontrol, SENSOR, true, false, "boolean");
    Property *volumedown = new Property("Volume -", "volumedown", ircontrol, SENSOR, true, false, "boolean");

    Property *channel1 = new Property("Channel 1", "channel1", ircontrol, SENSOR, true, false, "boolean");
    Property *channel2 = new Property("Channel 2", "channel2", ircontrol, SENSOR, true, false, "boolean");

    smartcloud.setup();
}
void loop() { smartcloud.loop(); }
