#pragma once

#include <ctre/Phoenix.h>

#include <Constants.h>

#include <iostream>

class Jacks {
public:
    Jacks();
    
    void init();

    void raise();
    void raiseFront();
    void lower();

    void update();    
    void drive(double rate);

private:
    WPI_TalonSRX front_left{JACKS::FRONT_LEFT::PORT}, front_right{JACKS::FRONT_RIGHT::PORT}, back{JACKS::BACK::PORT};
    WPI_TalonSRX driver{JACKS::DRIVER_PORT};
};