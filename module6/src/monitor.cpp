#include "monitor.h"
//-------------------------------------------------------------------------------------------------
CMonitor::CMonitor(const char* name):_brand_name(name), _screen_size(15), _power_supply(nullptr){
	_input_connections[0]	= E_VGA;
	_resolution				= E_FullHD;
	_refrash_rate			= 60;
}
CMonitor::CMonitor(const char* name, unsigned short scr_size, InputConnections inp_conn, const char* power_supply):_brand_name(name), _screen_size(scr_size) {
	_input_connections[0]	= inp_conn;
	_power_supply			= new CDevice(power_supply, 13);
	_resolution				= E_FullHD;
	_refrash_rate			= 60;
}
CMonitor::CMonitor(const CMonitor& other):_brand_name(other._brand_name), _screen_size(other._screen_size), _power_supply(other._power_supply) {
	for (int i = 0; i < E_IC_END;i++) {
		_input_connections[i] = other._input_connections[i];
	}
	_resolution		= other._resolution;
	_refrash_rate	= other._refrash_rate;
	_power_supply	= new CDevice(*other._power_supply);
}
CMonitor::~CMonitor() {
	if (_power_supply)
 		delete _power_supply;
}
//----------------------------------------------------------------------------------------------------------
//Setters
void CMonitor::set_resolution(ScreenResolution sr) {
	_resolution = sr;
}
void CMonitor::set_refreash_rate(unsigned short rr) {
	_refrash_rate = rr;
}

void CMonitor::add_connection(InputConnections new_conn) {
	for (int i = 0; i < E_IC_END; i++) {
		if (!_input_connections[i]) {
			_input_connections[i] = new_conn;
			break;
		}
	}
}
//----------------------------------------------------------------------------------------------------------
void CMonitor::ShowMenuName(unsigned short menu_id) {
	std::cout << menu_id + 1 << " - Монитор " << _brand_name << std::endl;
}
void CMonitor::ShowSpec() {
	std::string res{};

	std::cout << "(Monitor) Brand:" << _brand_name << std::endl;
	std::cout << "Supported connections:"<< std::endl;

	for (int i = 0; i < E_IC_END; i++) {
		if (!_input_connections[i]) continue;
		switch (_input_connections[i]) {
		case E_HDMI:
			res = "\t\t- HDMI";
			break;
		case E_DisplayPort:
			res = "\t\t- Display Port";
			break;
		case E_VGA:
			res = "\t\t- VGA";
			break;
		case E_DVI:
			res = "\t\t- DVI";
			break;
		}

		std::cout << res << std::endl;
		res.clear();
	}
	
	res.clear();

	switch (_resolution){
	case E_FullHD:
		res = "Full HD (1,920 x 1,080-pixel)";
		break;
	case E_4K_UHD:
		res = "4K UHD (3,840 x 2,160-pixel)";
		break;
	case E_8K_UHD:
		res = "8K UHD (7,680 x 4,320-pixel)";
		break;
	default:
		break;
	}

	std::cout << "\tScreen resolution:" << res << std::endl;
	std::cout << "\tScreen size:" << _screen_size <<" inch" << std::endl;
	std::cout << "\tScreen refreash rate:" << _refrash_rate << " Hz" << std::endl;
	std::cout << "\tBattary brand:" << _power_supply->get_name() << std::endl;
	std::cout << "\tBattary duration:" << _power_supply->get_battaryLife() << " hr" << std::endl;
}

