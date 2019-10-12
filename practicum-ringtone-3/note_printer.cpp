#include "hwlib.hpp"
#include "note_printer.hpp"

void note_printer::play( const note & n ){
    
    hwlib::cout<<n.frequency<<" "<<n.duration<<"\n";
}