#pragma once
#include "screen.h"
#include "device.h"

enum InputConnections {
	E_HDMI=1,
	E_DisplayPort,
	E_VGA,
	E_DVI,
	E_IC_END
};


class CMonitor : public CScreen {
public:
	CMonitor(const char*);
	CMonitor(const char*, unsigned short, InputConnections, const char*);
	CMonitor(const CMonitor&);
	~CMonitor();

	void ShowSpec() override;
	void ShowMenuName(unsigned short) override;


	void set_resolution(ScreenResolution);
	void set_refreash_rate(unsigned short);
	void add_connection(InputConnections);


private:
	const char* _brand_name = nullptr;
	unsigned short _screen_size;
	InputConnections _input_connections[E_IC_END]{};
	CDevice* _power_supply = nullptr;
};
