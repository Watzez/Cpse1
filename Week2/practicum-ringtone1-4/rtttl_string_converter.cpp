#include "hwlib.hpp"
#include "rtttl_string_converter.hpp"
#include <iostream>
#include <fstream>

void rtttl_string_converter::play( const note & n ){
   std::ofstream outfile;
   outfile.open("melody.cpp", std::ios::app);
   outfile << "      p.play( note{ " << n.frequency << ", " << n.duration << " } );" << "\n";
   outfile.close();
}
