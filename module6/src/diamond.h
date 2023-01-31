#pragma once
//ромбовидное наследование. С этим не соберётся ибо :
//	Error	LNK2001	unresolved external symbol "public: virtual void __cdecl CScreenDiamond::ShowSpec(void)....

#include "screen.h"
#include "device.h"


class CDimondDevice : public CScreenDiamond, CDeviceDimond {
public:
	CDimondDevice();
	~CDimondDevice() = default;
	CDimondDevice(const CDimondDevice&) = default;
	void ShowSpec() override;

};
