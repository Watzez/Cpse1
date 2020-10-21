#ifndef _OLEDCLOCK_HPP
#define _OLEDCLOCK_HPP
#include "cos_sin_lookup.hpp"

class oledclock{
private:
	hwlib::glcd_oled display;
	hwlib::target::pin_in swHours;
	hwlib::target::pin_in swMinutes;
	hwlib::target::pin_in swConfirm;
	const cos_lookup & coss;
	const sin_lookup & sins;
	unsigned int hours;
	unsigned int minutes;
public:
	oledclock( hwlib::glcd_oled display, hwlib::target::pin_in swHours, hwlib::target::pin_in swMinutes, hwlib::target::pin_in swConfirm, const cos_lookup & coss, const sin_lookup & sins ):
		display( display ),
		swHours( swHours ),
		swMinutes( swMinutes ),
		swConfirm( swConfirm ),
		coss( coss ),
		sins( sins )
	{ 	hours = 9; 
		minutes = 45;
	}
	void writeDisplay();
	void setMinutes();
	void setHours();
	void setTime();
	void trackTime();
};

#endif
