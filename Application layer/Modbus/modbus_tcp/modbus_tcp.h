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

#endif