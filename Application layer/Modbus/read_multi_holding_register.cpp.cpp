#include <iostream>
#include <memory>
#include <typeinfo>

#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

#define SLAVE_ADDRESS          	0x01
#define SOIL_HUMID_REG_MSB    	0x00
#define SOIL_HUMID_REG_LSB    	0x01
#define NUM_OF_REGISTER_MSB   	0x00
#define NUM_OF_REGISTER_LSB   	0x01

#define SERIAL_PORT				"/dev/ttyUSB0"

/*
	Namespace for public Function codes
*/
namespace function_code {
	constexpr int RD_MULTI_HLD_REGS = 0x03;// Read multiple holding registers
}

using namespace std;
using namespace function_code;

class MODBUS_RTU_Master {
	public:
		MODBUS_RTU_Master(const char* serial_port);

		template <typename T, int rtu_data_size>
		int form_modbus_rtu_frame(int slave_address, int function_code, T (&rtu_data)[rtu_data_size], std::unique_ptr<uint8_t[]> &modbus_rtu_frame);

		void send_modbus_rtu_frame(std::unique_ptr<uint8_t[]> modbus_rtu_frame, int modbus_rtu_frame_size);
	private:
		int _fd;
		int sender_crc_calculate(std::unique_ptr<uint8_t[]> &modbus_rtu_frame, int modbus_rtu_frame_size_without_crc);
};

MODBUS_RTU_Master::MODBUS_RTU_Master(const char* serial_port){
	_fd = open(serial_port, O_RDWR);
	if (_fd < 0) {
		cout << "Unable to open " << serial_port << endl;
		exit(0);
	}
}

/*
	Return: The newly formed Modbus RTU frame size
*/
template <typename T, int rtu_data_size>
int MODBUS_RTU_Master::form_modbus_rtu_frame(int slave_address, int function_code, T (&rtu_data)[rtu_data_size], std::unique_ptr<uint8_t[]> &modbus_rtu_frame){
	// Size of modbus_rtu_frame = 1 (slave_address) + 1 (function code) + rtu_data_size + 1 (LSB of CRC-16) + 1 (MSB of CRC-16)
	// = 4 + rtu_data_size

	int frame_sz = 4 + rtu_data_size;//Modbus RTU frame size
	modbus_rtu_frame = std::make_unique<uint8_t[]>(frame_sz);
	modbus_rtu_frame[0] = slave_address;
	modbus_rtu_frame[1] = function_code;
	
	for (int i = 2; i < frame_sz-2; i++){
		modbus_rtu_frame[i] = rtu_data[i-2];
	}

    int frame_sz_without_crc = frame_sz - 2;
	int crc_16_ibm = sender_crc_calculate(modbus_rtu_frame, frame_sz_without_crc);
	modbus_rtu_frame[frame_sz-2] = (uint8_t)crc_16_ibm;
	modbus_rtu_frame[frame_sz-1] = static_cast<uint8_t>(crc_16_ibm>>8);
	return frame_sz;
}

void MODBUS_RTU_Master::send_modbus_rtu_frame(std::unique_ptr<uint8_t[]> modbus_rtu_frame, int modbus_rtu_frame_size)
{
	#define READ_BUFFER           20
	uint8_t soil_sensor_data[READ_BUFFER];

	int wr_sz = write(_fd, modbus_rtu_frame.get(), modbus_rtu_frame_size);

	read(_fd, soil_sensor_data, READ_BUFFER);
	printf("%x %x %x %x %x %x\n", soil_sensor_data[0], soil_sensor_data[1], 
	soil_sensor_data[2], soil_sensor_data[3], 
	soil_sensor_data[4], soil_sensor_data[5]);
}

int MODBUS_RTU_Master::sender_crc_calculate(std::unique_ptr<uint8_t[]> &modbus_rtu_frame, int modbus_rtu_frame_size_without_crc){
    uint16_t crc_16_ibm = 0xffff;
    for (int i = 0; i < modbus_rtu_frame_size_without_crc; i++){
        crc_16_ibm ^= modbus_rtu_frame[i];
        for (int j = 0; j < 8; j ++){
            if ((crc_16_ibm & 0x01) == 1) crc_16_ibm = ((crc_16_ibm>>1)^0xa001);
            else crc_16_ibm = crc_16_ibm >> 1;
        }
    }
    return crc_16_ibm;
}

int main(){
	int rd_multi_hld_regs_data[] = {SOIL_HUMID_REG_MSB, SOIL_HUMID_REG_LSB, NUM_OF_REGISTER_MSB, NUM_OF_REGISTER_LSB};
	std::unique_ptr<uint8_t[]> modbus_rtu_frame;

	MODBUS_RTU_Master master(SERIAL_PORT);
	int frame_sz = master.form_modbus_rtu_frame(SLAVE_ADDRESS, function_code::RD_MULTI_HLD_REGS, rd_multi_hld_regs_data, modbus_rtu_frame);

	master.send_modbus_rtu_frame(std::move(modbus_rtu_frame), frame_sz);
    return 0;
}