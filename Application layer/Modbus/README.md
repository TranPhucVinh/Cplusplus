# Modbus RTU
Modbus RTU master/client reads multiple holding register of slave: [modbus_rtu_rd_multi_hld_reg.cpp](modbus_rtu_rd_multi_hld_reg.cpp). This example is intended for comprehensive and easy to understand the Modbus RTU operation. 

For slave to response data to this master program, use [diagslave](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Application%20layer/Modbus/Diagslave.md):

```sh
diagslave -b 115200 -p none -m rtu -a 1 /dev/ttyUSB0 #115200 is the default baudrate of Ubuntu serial port
```
# Modbus TCP
Modbus TCP master/client reads multiple holding registers of Modbus TCP slave/server on localhost, port 8000: [modbus_tcp_rd_multi_hld_reg.cpp](modbus_tcp_rd_multi_hld_reg.cpp).

For Modbus TCP slave to response data to this master program, use [diagslave](https://github.com/TranPhucVinh/Linux-Shell/blob/master/Application%20layer/Modbus/Diagslave.md):
```sh
diagslave -m tcp -p 8000 -a 1
```
