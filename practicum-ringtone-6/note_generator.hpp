#ifndef _NOTE_GENERATOR_HPP
#define _NOTE_GENERATOR_HPP

#include "note_player.hpp"

class note_generator : public note_player {

public: 
   void play( const note & n ) override;
};

#endif