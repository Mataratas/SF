#include "diamond.h"



CDimondDevice::CDimondDevice() {
	_battaryLife	= 13;
	_resolution	= E_FullHD;
	_refrash_rate	= 60;
}

void CDimondDevice::ShowSpec() {
	std::string res{};
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

	std::cout << "Diamond item: resolution - " << res << " refreash rate - " << _refrash_rate << " Hz" << " battary duration - "<< _battaryLife << std::endl;
}