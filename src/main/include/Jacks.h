#pragma once

#include <ctre/Phoenix.h>

#include <Constants.h>

#include <iostream>

class Jacks {
public:
    Jacks();
    
    void raise();
    void raiseFront();
    void raiseBackSmall();

    void lower();
    void lowerHAB2();
    void lowerHAB2to3();
    void lowerBackSmall();

    void update();    
    void drive(double rate);

    // Run these functions in small amounts so to not flood the CAN bus
    bool isFrontStopped();
    bool isBackStopped();

private:
    WPI_TalonSRX front_left{JACKS::FRONT_LEFT::PORT}, front_right{JACKS::FRONT_RIGHT::PORT}, back{JACKS::BACK::PORT};
    WPI_TalonSRX driver{JACKS::DRIVER_PORT};

    int fl, fr, b;
};