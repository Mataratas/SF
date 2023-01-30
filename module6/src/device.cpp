#include "device.h"
//============================================================================================================
CDevice::CDevice() :_battaryLife(0) {}
CDevice::CDevice(unsigned int b_life) :_battaryLife(b_life) {}
CDevice::CDevice(const char* name, unsigned int b_life) :_battaryLife(b_life),_name(name) {}
CDevice::CDevice(const CDevice& other):_battaryLife(other._battaryLife),_name(other._name) {




}



void CDevice::ShowSpec() {
	std::cout << "Device item: battary duration - " << _battaryLife<<" hr" << std::endl;
}

void CDevice::ShowMenuName(unsigned short menu_id) {
	std::cout << menu_id + 1 << " - Блок питания";
	if (!_name)
		std::cout <<" "<< _name << std::endl;
	else
		std::cout << "/n";
}

