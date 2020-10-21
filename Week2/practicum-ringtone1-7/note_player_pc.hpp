#ifndef _NOTE_PLAYER_PC_HPP
#define _NOTE_PLAYER_PC_HPP

#include "note_player.hpp"


class note_player_pc : public note_player {
public: 
   note_player_pc(){}
   
   void play( const note & n ) override;
};

#endif
