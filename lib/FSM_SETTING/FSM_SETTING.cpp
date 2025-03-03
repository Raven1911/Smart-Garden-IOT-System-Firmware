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
    if (Value_SoilMoisture <= 30){
        pump_on();
        ledred_on();
    }
    if (Value_SoilMoisture > 30){
        pump_off();
        ledgreen_on();
    }
    if (Value_Temperature >= 25){
        controlFan();
    }
    if (Value_Light <= 20 && Value_Light >= 0){
        ledwhite_on();
    }
}

void FSM_Manual(void){
    pump_control_manual(Pump1.active);
    fan_control_manual(255);

}