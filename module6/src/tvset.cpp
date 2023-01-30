#include "tvset.h"


//Почему нельзя при множественном наследовании в конструкторе потомка проинициализировать данные классов-предков
//через список инициализации?:
//	CTVSet::CTVSet() :_colorMode(E_PAL), _battaryLife(0), _resolution(E_FullHD), _refrash_rate(50) {}




CTVSet::CTVSet(const char* brand_name) :_colorMode(E_PAL), _brand_name(brand_name){
	_battaryLife	= 13;
	_resolution		= E_FullHD;
	_refrash_rate	= 50;
}

CTVSet::CTVSet(const char* brand_name, ColorMode color_mode, ScreenResolution sres, unsigned short ref_rate, unsigned int bat_life):_brand_name(brand_name), _colorMode(color_mode) {
	_battaryLife	= bat_life;
	_resolution		= sres;
	_refrash_rate	= ref_rate;
}


void CTVSet::set_screen_resolution(ScreenResolution sr) {
	_resolution = sr;
}
void CTVSet::set_screen_refreash_rate(unsigned short rr) {
	_refrash_rate = rr;
}



void CTVSet::ShowSpec() {
	std::string res{};

	switch (_colorMode) {
	case E_PAL:
		res = "PAL";
		break;
	case E_NTSC:
		res = "NTSC";
		break;
	case E_SECAM:
		res = "SECAM";
		break;
	}

	std::cout << "(TV set) Brand:" << _brand_name << std::endl;
	std::cout << "\tColor scheme:" << res << std::endl;

	res.clear();


	switch (_resolution)
	{
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
	std::cout << "\tScreen refreash rate:" << _refrash_rate<< " Hz" << std::endl;
	std::cout << "\tBattary duration:" << _battaryLife <<" hr" << std::endl;
}

void CTVSet::ShowMenuName(unsigned short menu_id) {
	std::cout << menu_id + 1 << " - Телевизор "<<_brand_name<<std::endl;
}