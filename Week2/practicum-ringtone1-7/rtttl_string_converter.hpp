#ifndef _RTTTL_STRING_CONVERTER_HPP
#define _RTTTL_STRING_CONVERTER_HPP

#include "note_player.hpp"

class rtttl_string_converter : public note_player {
public: 
   rtttl_string_converter(){}   
   void play( const note & n ) override;
};

#endif
