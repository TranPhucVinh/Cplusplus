#include <iostream>      
#include <string>
#include <sys/socket.h> /* for socket(), connect()*/
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <unistd.h>     /* for close() */

#define HOST "127.0.0.1"
#define PORT 8000

using namespace std;

class UDP_SNDR {
    private:
        int _sender_fd;
        struct sockaddr_in _rx_addr;
    public:
        UDP_SNDR(const char *host, int port); 
        ~UDP_SNDR();
        ssize_t send_msg(string msg);
};

UDP_SNDR::UDP_SNDR(const char *host, int port){
    _rx_addr.sin_family      = PF_INET;
    _rx_addr.sin_addr.s_addr = inet_addr(host);
    _rx_addr.sin_port        = htons(port);

    // Create UDP socket
    if ((_sender_fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
        cout << "Fail to create UDP socket\n";
        exit(0);
    } else cout << "Create UDP socket successfully\n";
}

UDP_SNDR::~UDP_SNDR() {
    close(_sender_fd);
}

ssize_t UDP_SNDR::send_msg(string msg) {
    ssize_t snd_bytes = sendto(_sender_fd, msg.c_str(), msg.size(), MSG_CONFIRM, (struct sockaddr *) &_rx_addr, sizeof(_rx_addr));
    return snd_bytes;
}

int main(){
    UDP_SNDR udp_sender(HOST, PORT);

    int index = 0;
    while(1){
        string snd_str = "Hello, World !; index " + to_string(index);
        ssize_t snd_bytes = udp_sender.send_msg(snd_str);        
        if (snd_bytes <= 0) {
            cout << "Fail to send message\n";
            return -1;
        }
        cout << "Mesage '" << snd_str << "' has been sent\n";
        index += 1; 
        sleep(1);
    }
    return 0;
}
