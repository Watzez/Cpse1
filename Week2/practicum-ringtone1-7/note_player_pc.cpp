#include "note_player_pc.hpp"
#include <iostream>

void note_player_pc::play( const note & n ){
   std::cout << n.frequency << ", " << n.duration << "\n"; 
}
