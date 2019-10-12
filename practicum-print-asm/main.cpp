#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

// extern "C" void toggle_char( char c ){
//    if(c >= 65 && c <= 90){
//       c = c + 32;
//    }else if(c >= 97 && c <= 122){
//       c = c - 32;
//    }
//    uart_put_char(c);
// }

//extern "C" void print_asciz( const char * s );
//    while( *s != '\0'){
//       uart_put_char( *s );
//       ++s;
//    }


extern "C" void application();
//    print_asciz( "Hello world\n" );	


int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

      application();
}