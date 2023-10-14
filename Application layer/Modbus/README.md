# Modbus RTU
Modbus RTU master/client reads multiple holding register of slave: [modbus_rtu_rd_multi_hld_reg.cpp](modbus_rtu_rd_multi_hld_reg.cpp). This example is intended for comprehensive and easy to understand the Modbus RTU operation. 

For slave to response data to this master program, use [diagslave]():

```sh
diagslave -b 115200 -p none -m rtu -a 1 /dev/ttyUSB0 #115200 is the default baudrate of Ubuntu serial port
```