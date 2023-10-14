Modbus RTU master/client reads multiple holding register of slave: [read_multi_holding_register.cpp.cpp](read_multi_holding_register.cpp.cpp). This example is intended for comprehensive and easy to understand the Modbus RTU operation. 

For slave to response data to this master program, use [diagslave]():

```sh
diagslave -b 115200 -p none -m rtu -a 1 /dev/ttyUSB0 #115200 is the default baudrate of Ubuntu serial port
```