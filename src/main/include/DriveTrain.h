#pragma once

#include <ctre/Phoenix.h>
#include <frc/Solenoid.h>

#include <Transmission.h>
#include <Constants.h>

class DriveTrain {
public:
    DriveTrain();
    void tank(double lrate, double rrate);
    void shift(bool toshift);
private:
    Transmission<WPI_TalonSRX> ltrm, rtrm;
    frc::Solenoid shifter;

};