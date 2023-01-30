#include "device.h"
#include "screen.h"
#include "tvset.h"
#include "mvoven.h"
#include "monitor.h"




int main(int argc, char** argv) {

	setlocale(LC_ALL, "");

	IElectronics* warehouse[5]{};
	
	warehouse[0] =	new CTVSet("Philips",E_PAL,E_FullHD,80,34);
	warehouse[1] =	new CTVSet("Samsung",E_NTSC,E_4K_UHD,100,115);
	warehouse[2] =	new CMWaveOven("Panasonic", 23, 285, 950, 6.2f, 1500, 9.5f);
	warehouse[3] =	new CMonitor("BenQ", 15, E_HDMI, "Ippon");

	CMonitor *mptr = new CMonitor("Vision", 21, E_HDMI, "Powercom");
	mptr->add_connection(E_DVI);
	mptr->add_connection(E_VGA);
	mptr->set_resolution(E_8K_UHD);
	mptr->set_refreash_rate(100);

	warehouse[4] = mptr;
	
	unsigned short arr_size = *(&warehouse + 1) - warehouse;

	while (true) {
		unsigned short choice(0);
		std::cout << "-----------------------------------------------------------------------------------\n";
		std::cout << "Выберите товар для просмотра его характеристик:\n";
		for (unsigned short i =0;i< arr_size;i++)
			warehouse[i]->ShowMenuName(i);
		std::cout << "0 - выход\n";
		std::cout << "-----------------------------------------------------------------------------------\n";

		std::cin >> choice;

		if (choice >= 1 && choice <= arr_size)
			warehouse[choice - 1]->ShowSpec();
		else
			break;
	}



	for (auto dptr : warehouse) {
		if (dptr) 
			delete dptr;
	}
	
	return 0;
  }