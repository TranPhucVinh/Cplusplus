#include <iostream>  
#ifndef modbus_tcp_h
#define modbus_tcp_h

#include <memory>
#include <typeinfo>

#include <sys/socket.h> /* for socket(), connect()*/
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <errno.h>

using namespace std;

namespace function_code {
	constexpr int RD_MULTI_HLD_REGS = 0x03;// Read multiple holding registers
}

class Modbus_TCP_Client {
	public:
		Modbus_TCP_Client(const char* host, int port);
        ~Modbus_TCP_Client();

        template <typename T, int tcp_data_size>
        int form_modbus_tcp_frame(int trans_id, uint8_t slave_address, uint8_t function_code, T (&tcp_data)[tcp_data_size], std::unique_ptr<uint8_t[]> &modbus_tcp_frame);
        
        void send_modbus_tcp_frame(std::unique_ptr<uint8_t[]> &modbus_tcp_frame, int modbus_tcp_frame_size);

        template <typename T, int recv_buf_sz>
        void recv_from_modbus_tcp_server(T (&recv_buf)[recv_buf_sz]);
	private:
        int _server_fd;
        void error(const char *msg);
};

/*
    As every function code has its own structure of response frame, this function is generally
    used to read the Modbus response into a buffer.

    For any specific function to read the responsed of a specific function code, define that
    function with a correct size of the response buffer to store the response of that function code
*/
template <typename T, int recv_buf_sz>
void Modbus_TCP_Client::recv_from_modbus_tcp_server(T (&recv_buf)[recv_buf_sz])
{
    int sz = read(_server_fd, recv_buf, recv_buf_sz);
}

template <typename T, int tcp_data_size>
int Modbus_TCP_Client::form_modbus_tcp_frame(int trans_id, uint8_t slave_address, uint8_t function_code, T (&tcp_data)[tcp_data_size], std::unique_ptr<uint8_t[]> &modbus_tcp_frame)
{
    // Size of modbus_tcp_frame = 2 (transaction ID) + 2 (protocol ID) + 2 (length) + 1 (Unit ID/slave address) + 1 (function code) + tcp_data_size
	// = 8 + tcp_data_size

	int frame_sz = 8 + tcp_data_size;//Modbus tcp frame size
	modbus_tcp_frame = std::make_unique<uint8_t[]>(frame_sz);

    uint8_t trans_id_lsb = (uint8_t)trans_id;  //0x34, last byte
    uint8_t trans_id_msb = trans_id>>8;       //0x12; first byte

	modbus_tcp_frame[0] = trans_id_msb;
	modbus_tcp_frame[1] = trans_id_lsb;

    modbus_tcp_frame[2] = 0x00;// Protocol ID high byte = 0 for TCP 
	modbus_tcp_frame[3] = 0x00;// Protocol ID low byte = 0 for TCP 

    int length = 2 + tcp_data_size;//length = 1 byte (slave_address) + 1 byte (function_code) + tcp_data_size;

	uint8_t length_lsb = (uint8_t)length;
    uint8_t length_msb = length>>8; 

    modbus_tcp_frame[4] = length_msb;
	modbus_tcp_frame[5] = length_lsb;

    modbus_tcp_frame[6] = slave_address;
    modbus_tcp_frame[7] = function_code;

	for (int i = 0; i < tcp_data_size; i++){
		modbus_tcp_frame[8+i] = tcp_data[i];
	}

 	return frame_sz;
}

#endif
