#ifndef BUTTON_HPP
#define BUTTON_HPP

class button{
private:
    hwlib::pin_in & bt1_input;
    hwlib::pin_in & bt2_input;
public:
    button(hwlib::pin_in & bt1_input, hwlib::pin_in & bt2_input):
    bt1_input (bt1_input),
    bt2_input (bt2_input)
    {}

    bool update_bt1(){
        bt1_input.refresh();
        return bt1_input.read();
    }
    bool update_bt2(){
        bt2_input.refresh();
        return bt2_input.read();
    }
};

#endif