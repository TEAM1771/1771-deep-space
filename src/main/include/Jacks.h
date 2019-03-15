#pragma once

#include <ctre/Phoenix.h>

#include <Constants.h>

#include <iostream>

class Jacks {
public:
    Jacks();
    
    void raise();
    void raiseFront();
    void lower();
    void lowerHAB2();
    void lowerHAB2to3();
    void lowerBackSmall();
    void raiseBackSmall();

    void update();    
    void drive(double rate);

private:
    WPI_TalonSRX front_left{JACKS::FRONT_LEFT::PORT}, front_right{JACKS::FRONT_RIGHT::PORT}, back{JACKS::BACK::PORT};
    WPI_TalonSRX driver{JACKS::DRIVER_PORT};

    int fl, fr, b;
};