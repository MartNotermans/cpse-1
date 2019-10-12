#include "hwlib.hpp"
#include "note_generator.hpp"

#include <iostream>
#include <fstream>

void note_generator::play( const note & n ){
    //hwlib::cout<<n.frequency<<" "<<n.duration<<"\n";

    // std::ofstream outfile ("song.cpp");
    // outfile << "testing" <<std::endl;
    // outfile.close();

    std::fstream fs;
    fs.open ("song.hpp", std::fstream::in | std::fstream::out | std::fstream::app);

    fs << "      p.play( note{ " << n.frequency << ", " << n.duration << " } );\n";

    fs.close();
}