#include "modbus_tcp.h"

void Modbus_TCP_Client::error(const char *msg){
    perror(msg);
    exit(0);
}
 
Modbus_TCP_Client::Modbus_TCP_Client(const char* host, int port)
{
    struct sockaddr_in receiver_addr;
    receiver_addr.sin_family      = PF_INET;
    receiver_addr.sin_addr.s_addr = inet_addr(host);          
    receiver_addr.sin_port        = htons(port);

    // Create TCP socket
    if ((_server_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        cout << "Fail to create socket\n";
        exit(0);
    } else cout <<  "Create socket successfully\n";

    // Connect to server
    if (connect(_server_fd, (struct sockaddr *)&receiver_addr, sizeof(receiver_addr)) < 0){
        if (errno == ECONNREFUSED) {
            cout <<  "Server hasn't been started or server doesn't support connection\n";
        } else cout << "Can't connect to server with error " <<  errno << endl;
        exit(0);
    } else cout << "connect to Modbus TCP server success\n";
}

Modbus_TCP_Client::~Modbus_TCP_Client(){
    close(_server_fd); //Close socket
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

void Modbus_TCP_Client::send_modbus_tcp_frame(std::unique_ptr<uint8_t[]> &modbus_tcp_frame, int modbus_tcp_frame_size){
    int sz = write(_server_fd, modbus_tcp_frame.get(), modbus_tcp_frame_size);    
}

template <typename T, int recv_buf_sz>
void Modbus_TCP_Client::recv_from_modbus_tcp_server(T (&recv_buf)[recv_buf_sz])
{
    int sz = read(_server_fd, recv_buf, recv_buf_sz);
}