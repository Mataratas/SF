#pragma once
#include "device.h"

class CMWaveOven final : public CDevice {
public:
	CMWaveOven(const char*);
	CMWaveOven(const char*, unsigned short, unsigned short, unsigned short, float, float, float);
	~CMWaveOven() = default;
	CMWaveOven(const CMWaveOven&) = default;
	void ShowSpec() override;
	void ShowMenuName(unsigned short) override;

	inline const char* get_name() const;
	inline unsigned short get_capacity() const;
	inline unsigned short get_power() const;
	inline unsigned short get_turntable_size() const;
	float  get_max_power_input(char) const;
	inline float get_weight() const;

	void set_capacity(unsigned short);
	void set_power(unsigned short);
	void set_turntable_size(unsigned short);
	void set_max_power_input(float, char);
	void set_weight(float);
	void set_battary_duration(unsigned int);

private:

	const char* _brand_name = nullptr;

	unsigned short _capacity;
	unsigned short _mw_power;
	unsigned short _turntable;

	float _max_power_input_w;
	float _max_power_input_a;
	float _net_weight;




};