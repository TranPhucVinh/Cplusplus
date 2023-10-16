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

void Modbus_TCP_Client::send_modbus_tcp_frame(std::unique_ptr<uint8_t[]> &modbus_tcp_frame, int modbus_tcp_frame_size){
    int sz = write(_server_fd, modbus_tcp_frame.get(), modbus_tcp_frame_size);    
}
