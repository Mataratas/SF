#include "screen.h"

CScreen::CScreen():_resolution(E_FullHD), _refrash_rate(50) {}
CScreen::CScreen(ScreenResolution resl, unsigned short refr_rate) :_resolution(resl), _refrash_rate(refr_rate) {}
void CScreen::ShowSpec() {
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

	std::cout << "Screen item: resolution - " << res <<" refreash rate - "<< _refrash_rate<<" Hz" << std::endl;
}

void CScreen::ShowMenuName(unsigned short menu_id) {
	std::cout << menu_id + 1 << " - Монитор\n";
}

