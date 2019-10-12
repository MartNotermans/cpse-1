#ifndef _FUR_ELISE_HPP
#define _FUR_ELISE_HPP

#include "melody.hpp"
class fur_elise : public melody {
public:
   void play( note_player & p ){
      p.play( note{ 880, 1000000 } );
      p.play( note{ 0, 1000000 } );
      p.play( note{ 880, 1000000 } );
      p.play( note{ 0, 1000000 } );
      p.play( note{ 880, 1000000 } );
      p.play( note{ 0, 1000000 } );
      p.play( note{ 880, 2000000 } );
      p.play( note{ 0, 1000000 } );
      p.play( note{ 880, 2000000 } );
      p.play( note{ 0, 1000000 } );
      p.play( note{ 880, 2000000 } );
      p.play( note{ 0, 1000000 } );
      p.play( note{ 880, 1000000 } );
      p.play( note{ 0, 1000000 } );
      p.play( note{ 880, 1000000 } );
      p.play( note{ 0, 1000000 } );
      p.play( note{ 880, 1000000 } );
    }
};

#endif