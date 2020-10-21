#include "hwlib.hpp"
#include "oledclock.hpp"
#include "cos_sin_lookup.hpp"

int main( void ){	  
	constexpr cos_lookup coss;
	constexpr sin_lookup sins;

   	namespace target = hwlib::target;
   
  	auto scl = target::pin_oc( target::pins::scl );
   	auto sda = target::pin_oc( target::pins::sda );
   
   	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
	auto swHours = hwlib::target::pin_in( hwlib::target::pins::d8 );
   	auto swMinutes = hwlib::target::pin_in( hwlib::target::pins::d9 );
	auto swConfirm = hwlib::target::pin_in( hwlib::target::pins::d10);

	auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  
	display.clear();

	auto clock = oledclock( display, swHours, swMinutes, swConfirm, coss, sins );
	clock.trackTime();
}
