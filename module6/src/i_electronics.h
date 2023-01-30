#pragma once
#include <iostream>

class IElectronics {
public:
	virtual void ShowSpec() = 0;
	virtual void ShowMenuName(unsigned short) = 0;
	virtual ~IElectronics() = default;
};

