#include "mvoven.h"
//--------------------------------------------------------------------------------------------------------
CMWaveOven::CMWaveOven(const char* name) :_brand_name(name),_capacity(0),_mw_power(0),_turntable(0),_max_power_input_a(0),_max_power_input_w(0),_net_weight(0) {}


CMWaveOven::CMWaveOven(const char* name, unsigned short capacity, unsigned short mw_power, unsigned short turntable, float max_p_a, float max_p_w, float weight):_brand_name(name),
 _capacity(capacity), _mw_power(mw_power), _turntable(turntable), _max_power_input_a(max_p_a), _max_power_input_w(max_p_w), _net_weight(weight){}

//------------------------------------------------------------------------------------------------------------
//Getters
inline const char* CMWaveOven::get_name() const {
	return _brand_name;
}
inline unsigned short CMWaveOven::get_capacity() const {
	return _capacity;
}
inline unsigned short CMWaveOven::get_power() const {
	return _mw_power;
}
inline unsigned short CMWaveOven::get_turntable_size() const {
	return _turntable;
}
float  CMWaveOven::get_max_power_input(char mesure = 'w') const {
	if (mesure == 'w')
		return _max_power_input_w;
	else
		return _max_power_input_a;
}
inline float CMWaveOven::get_weight() const {
	return _net_weight;
}

//Setters----------------------------------------------------------------------------------------
void CMWaveOven::set_capacity(unsigned short cap) {
	_capacity = cap;
}
void CMWaveOven::set_power(unsigned short mwpw) {
	_mw_power = mwpw;
}
void CMWaveOven::set_turntable_size(unsigned short ttsize) {
	_turntable = ttsize;
}
void CMWaveOven::set_max_power_input(float v, char mesure = 'w') {
	if (mesure == 'w')
		_max_power_input_w = v;
	else
		_max_power_input_a = v;

}
void CMWaveOven::set_weight(float weight) {
	_net_weight = weight;
}
void CMWaveOven::set_battary_duration(unsigned int duration) {
	_battaryLife = duration;
}
//------------------------------------------------------------------------------------------------------------
void CMWaveOven::ShowSpec() {

	std::cout << "(Micro wave oven) Brand:" << _brand_name << std::endl;
	std::cout << "\tCapacity:" << _capacity <<"L" << std::endl;
	std::cout << "\tMicrowave Power:" << _mw_power << "W" << std::endl;
	std::cout << "\tTurntable size:" << _turntable << "mm" << std::endl;
	std::cout << "\tMaximum Power Input:" << _max_power_input_w << "W "<< _max_power_input_a<<"A" << std::endl;
	std::cout << "\tNet Weight:" << _net_weight << "kg" << std::endl;
	std::cout << "\tBattary duration:" << _battaryLife << " hr" << std::endl;

}

void CMWaveOven::ShowMenuName(unsigned short menu_id) {
	std::cout << menu_id + 1 << " - ÑÂ×\n";
}