#include <iostream>      
#include <string>
#include <vector>
#include <sys/socket.h> /* for socket(), connect()*/
#include <arpa/inet.h>  /* for sockaddr_in */
#include <unistd.h>     /* for close() */

#define PORT 8000

using namespace std;

class UDP_RX {
    private:
        int _rx_fd;
        struct sockaddr_in _rx_addr;
        socklen_t _src_addr_len;
    public:
        UDP_RX(int port); 
        ~UDP_RX();
        void rx_msg(vector<char> &buffer);
};

UDP_RX::UDP_RX(int port) {
    _src_addr_len = sizeof(struct sockaddr_in);  //len is value/result

    _rx_fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (_rx_fd < 0){
        perror("receiver_fd\n");
    } else cout << "Create UDP receiver socket successfully\n";
 
    _rx_addr.sin_family = PF_INET;                
    _rx_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
    _rx_addr.sin_port = htons(port);      

    //Bind to the local address
    if (bind(_rx_fd, (struct sockaddr *)&_rx_addr, sizeof(_rx_addr)) < 0) {
        cout << "Fail to bind UDP socket to local address\n";
        exit(0);
    }
    else cout << "Start UDP socket receiver successfully through binding\n";
}

UDP_RX::~UDP_RX() {
    close(_rx_fd);
}

void UDP_RX::rx_msg(vector<char> &buffer) {
    recvfrom(_rx_fd, buffer.data(), buffer.size(), MSG_WAITALL, (struct sockaddr *) &_rx_addr, &_src_addr_len);
}

int main() {
    vector<char> buffer(50);

    UDP_RX udp_receiver(PORT);

    while(1){
        udp_receiver.rx_msg(buffer);
        string rx_str = string(buffer.begin(), buffer.end());
        cout << rx_str << endl;
    }
}
