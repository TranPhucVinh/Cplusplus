# MQTT client subscribe
For MQTT client publish and subscribe message, **aws.greengrass.ipc.mqttproxy** is required for the recipe JSON file in **accessControl** field:

```json
"accessControl": {
    "aws.greengrass.ipc.mqttproxy": {
        "<comp_name>:mqttproxy:1": {
        "policyDescription": "Allows access to subscribe to test/topic",
        "operations": [
            "aws.greengrass#SubscribeToIoTCore"
        ],
        "resources": [
            "<topic_string>"
        ]
        }
    }
}
```

Recipe json file of this component is [mqtt_sub.json](mqtt_sub.json)

Source code: [mqtt_sub.cpp](mqtt_sub.cpp). **CMakeLists.txt** file will be like the [local IPC publish/subscribe components]().

Once the component is running, to test it, from publisher side, we can use the **MQTT test client** from **AWS Management console**:

From the AWS Management console, head to AWS IoT Core, choose ``MQTT test client``. Choose ``Publish to a topic``, then add the topic and message to published. 

Once publishing the message, ``mqtt_sub`` component will receive that.
