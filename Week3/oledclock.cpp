#include "hwlib.hpp"
#include "oledclock.hpp"
//#include <cmath>

void oledclock::writeDisplay(){
	display.clear();
	for( int i = 0; i < 22; i++ ){
		display.write( hwlib::xy( coss.get(minutes) * i + 64, sins.get(minutes) * i + 32 ) );
	}

	for( int i = 0; i < 12; i++ ){
		display.write( hwlib::xy( coss.get(hours*5) * i + 64, sins.get(hours*5) * i + 32 ) );
	}

	for( int i = 0; i < 60; i+=5 ){
		display.write( hwlib::xy( coss.get(i) * 23 + 64, sins.get(i) * 23 + 32 ) );
	}
	display.flush();
}

void oledclock::setMinutes(){
	minutes++;
	minutes = minutes % 60;
}

void oledclock::setHours(){
	hours++;
	hours = hours % 12;
}

void oledclock::setTime(){
	hwlib::wait_ms( 250 );
	for(;;){	
			if( !swConfirm.read() ){
				break;
			}
			if( !swHours.read() ){
				setHours();
			}
			if( !swMinutes.read() ){
				setMinutes();
			}
			swHours.refresh();
			swMinutes.refresh();
			swConfirm.refresh();
			writeDisplay();
		}
}

void oledclock::trackTime(){
	int timeGlitch = 0;
	int currentTime = hwlib::now_us() / 1000000;
	bool changed = 0;
	hwlib::wait_ms( 1000 );
	for(;;){
		currentTime = hwlib::now_us() / 1'000'000;
		hwlib::cout << currentTime % 60 << "\n";
		if( !swConfirm.read() ){
			setTime();
			timeGlitch = ( hwlib::now_us() / 1000000 ) % 60;
			hwlib::wait_ms( 1000 );
		}
		if( ( (currentTime % 60) == timeGlitch ) && !changed ){
			changed = 1;
			hwlib::cout << "Turn up minuutje erbij: "<< timeGlitch << "\n";
			minutes++;
			minutes = minutes % 60;
			if( minutes == 45 ){
				hours++;
				hours = hours % 12;
			}
		}
		if( changed && ( ( currentTime % 60 ) != timeGlitch ) ){
			changed = 0;
		}

		writeDisplay();
		swConfirm.refresh();
		hwlib::wait_ms( 10 );
	}
}
