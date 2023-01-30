#pragma once
#include "i_electronics.h"


enum ScreenResolution{
	E_FullHD,
	E_4K_UHD,
	E_8K_UHD
};


class CScreen:virtual public IElectronics{
public:
	CScreen();
	CScreen(ScreenResolution, unsigned short);
	~CScreen() = default;
	CScreen(const CScreen&) = default;
	void ShowSpec() override;
	void ShowMenuName(unsigned short) override;
protected:
	ScreenResolution _resolution;
	unsigned short _refrash_rate;
};

class CScreenDiamond :public IElectronics { //to produce error in multiple inheritance
public:
	CScreenDiamond() :_resolution(E_FullHD), _refrash_rate(0) {};
	CScreenDiamond(ScreenResolution resl, unsigned short rr):_resolution(resl), _refrash_rate(rr) {};
	void ShowSpec() override;
	~CScreenDiamond() = default;

protected:
	ScreenResolution _resolution;
	unsigned short _refrash_rate;

};