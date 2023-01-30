#pragma once
#include "device.h"
#include "screen.h"

enum ColorMode{
	E_PAL,
	E_SECAM,
	E_NTSC,
	E_CM_END
};



class CTVSet final :public CDevice, CScreen {
public:
	CTVSet(const char*);
	CTVSet(const char*, ColorMode, ScreenResolution,unsigned short,unsigned int);
	~CTVSet() = default;
	CTVSet(const CTVSet&) = default;

	void ShowSpec() override;
	void ShowMenuName(unsigned short) override;
	inline void set_screen_resolution(ScreenResolution);
	inline void set_screen_refreash_rate(unsigned short);

private:
	ColorMode _colorMode;
	const char* _brand_name;

};
