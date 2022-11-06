#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "coreMQTT/source/include/core_mqtt_serializer.h"
#include "coreMQTT/source/include/core_mqtt.h"


int main() {

    printf("Hello MQTT!\n");

    MQTTContext_t * pContext;

    MQTT_Ping(pContext);



    return 0;



}
