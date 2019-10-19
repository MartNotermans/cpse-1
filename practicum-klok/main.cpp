#include "hwlib.hpp"
#include "coordinates.hpp"
#include "clock.hpp"
#include "draw.hpp"
#include "button.hpp"

int main( void ){	
    // wait for the PC console to start
    hwlib::wait_ms( 500 );   
   
    constexpr coordinates cords;
    
    
	auto gnd    = hwlib::target::pin_out( hwlib::target::pins::d6 );
    auto vcc    = hwlib::target::pin_out( hwlib::target::pins::d7 );
    gnd.write( 0 );
    vcc.write( 1 );
    gnd.flush();
    vcc.flush();

    auto bt1_input 	= hwlib::target::pin_in ( hwlib::target::pins::d3 );
    auto bt2_input 	= hwlib::target::pin_in ( hwlib::target::pins::d4 );

    namespace target = hwlib::target;
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );

    // use the buffered version
    auto oled = hwlib::glcd_oled( i2c_bus, 0x3c );  

    clock oledClock(cords, oled);
    
    button buttons(bt1_input, bt2_input);

    int time[2] = {0,15};
    oledClock.update(time);

    // for(;;){
    //     hwlib::cout<<buttons.update_bt1()<<";"<<buttons.update_bt2()<<hwlib::endl;
    // }


    for(;;){
        for(int i = 0; i < 100; i++){
            if(buttons.update_bt1() ){
                time[0]++;
                
                oledClock.update(time);
                hwlib::wait_ms(100);
            }
            if(time[0] > 11){
                time[0] = 0;
            }

            if(buttons.update_bt2() ){
                time[1]++;
                
                oledClock.update(time);
                hwlib::wait_ms(100);
            }
            if(time[1] > 59){
                time[1] = 0;
            }

            hwlib::wait_ms(10);
        }
        hwlib::cout<<time[0]<<":"<<time[1]<<hwlib::endl;
        
    }
    
    
}

