#pragma once

#include <ctre/Phoenix.h>
#include <Transmission.h>
#include <Constants.h>

class DriveTrain {
public:
    DriveTrain();
    void tank(double lrate, double rrate);
private:
    Transmission<WPI_TalonSRX> ltrm, rtrm;
};