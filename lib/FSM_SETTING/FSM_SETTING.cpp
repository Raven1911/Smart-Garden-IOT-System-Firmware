#include <FSM_SETTING.hpp>



void FSM_Main(void){
    if (State_FSM){
        FSM_Manual();
    }
    else {
        FSM_Auto();
    }
}

void FSM_Auto(void){
    // my le
    if (Value_SoilMoisture <= 30){
        pump_on();
    }
    if (Value_SoilMoisture > 30){
        pump_off();
    }
    if (Value_Temperature >=25){
        controlFan();
    }

}

void FSM_Manual(void){
    // my le
}