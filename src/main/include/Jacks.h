#pragma once

#include <ctre/Phoenix.h>

#include <Constants.h>

class Jacks {
public:
    Jacks();
    
    void init();

    void raise();
    void raiseFront();

    void lower();
    
    void drive(double rate);

private:
    WPI_TalonSRX front_left{JACKS::FRONT_LEFT_PORT}, front_right{JACKS::FRONT_RIGHT_PORT}, back{JACKS::BACK_PORT};
    WPI_TalonSRX driver{JACKS::DRIVER_PORT};
};