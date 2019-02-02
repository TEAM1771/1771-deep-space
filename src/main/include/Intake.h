#pragma once

#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>

#include <Constants.h>

class Intake {
public:
    Intake();

    void set(double rate);
    void demago(bool rgon);

private:
    WPI_TalonSRX roller;
    frc::Solenoid demagorgon;
};