#pragma once
#include "i_electronics.h"


class CDevice :virtual public IElectronics {
public:
	CDevice();
	CDevice(unsigned int);
	CDevice(const char*, unsigned int);
	CDevice(const CDevice&);
	~CDevice() = default;
	inline unsigned int get_battaryLife() const { return _battaryLife; }
	inline const char *get_name() const { return _name; }
	
	void ShowSpec() override;
	void ShowMenuName(unsigned short) override;
	
	
protected:
	unsigned int _battaryLife;
	const char* _name = nullptr;
};

class CDeviceDimond :public IElectronics { //to produce error in multiple inheritance
public:
	CDeviceDimond() :_battaryLife(0) {};
	CDeviceDimond(unsigned int bl) :_battaryLife(bl) {};
	void ShowSpec() override;
	~CDeviceDimond() = default;
protected:
	unsigned int _battaryLife;
	
};
