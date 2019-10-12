#ifndef DRAW_HPP
#define DRAW_HPP

#include "hwlib.hpp"

class drawable {
protected:

   hwlib::window & w;
   hwlib::xy location;
   
public:

   drawable( hwlib::window & w, const hwlib::xy & location ):
      w( w ),
      location( location )
   {}      
   
   virtual void draw() = 0;
   virtual void update(){}
};

class line : public drawable {
private:

   hwlib::xy end;
   
public:

   line( hwlib::window & w, const hwlib::xy & location, const hwlib::xy & end ):
      drawable( w, location ),
      end( end )
   {}
   
   void draw(){
      hwlib::line x( location, end );
      x.draw( w );;
   }
};

class circle : public drawable {
protected:

   int radius;
 
public:

   circle( hwlib::window & w, const hwlib::xy & midpoint, int radius ):
      drawable( w, midpoint ),
      radius( radius )
   {}
   
   void draw(){
      hwlib::circle c( location, radius );
      c.draw( w );
   }
};

#endif