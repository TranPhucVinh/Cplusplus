#include <iostream>
#include <vector>
using namespace std;

class Protocol_Message {
    public:
        void msg_parsing(vector<uint8_t> value);
		uint8_t dcd_header[1];
        uint8_t id[2];
        uint8_t env_humid[2];
        uint8_t env_temp[2];
        uint8_t soil_humid[2];
        uint8_t soil_temp[2];
        uint8_t checksum[1];
};

int main(){
	vector<uint8_t> value = {0x24, 0x00, 0x01, 0x1A, 0x05, 0x1f, 0x20, 0x2F, 0x1C, 0x17, 0x20, 0x61};

    Protocol_Message msg;
    msg.msg_parsing(value);
    printf("0x%x\n", msg.dcd_header[0]);
    printf("ID: 0x%x 0x%x\n", msg.id[0], msg.id[1]);

    printf("env_humid: 0x%x 0x%x\n", msg.env_humid[0], msg.env_humid[1]);
    printf("env_temp: 0x%x 0x%x\n", msg.env_temp[0], msg.env_temp[1]);
    printf("soil_humid: 0x%x 0x%x\n", msg.soil_humid[0], msg.soil_humid[1]);
    printf("soil_temp: 0x%x 0x%x\n", msg.soil_temp[0], msg.soil_temp[1]);

    printf("checksum: 0x%x\n", msg.checksum[0]);
}

void Protocol_Message::msg_parsing(vector<uint8_t> value){
    copy(value.begin(), value.end(),  reinterpret_cast<uint8_t*>(this));
}
