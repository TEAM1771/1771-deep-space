#pragma once

#include <math.h>

#include <ctre/Phoenix.h>
#include <frc/Solenoid.h>

#include <Transmission.h>
#include <Constants.h>

class DriveTrain {
public:
    DriveTrain();
    void tank(double lrate, double rrate);
    void shift(bool toshift);
    void shift();

    void init();

private:
    Transmission<WPI_TalonSRX> ltrm{{
        {DRIVETRAIN::LTRANS::MTRA, Direction::Forward}, 
        {DRIVETRAIN::LTRANS::MTRB, Direction::Forward}
    }, {DRIVETRAIN::LTRANS::ENCA, DRIVETRAIN::LTRANS::ENCB} }, 
    rtrm{{
        {DRIVETRAIN::RTRANS::MTRA, Direction::Reverse},
        {DRIVETRAIN::RTRANS::MTRB, Direction::Reverse}
    }, {DRIVETRAIN::RTRANS::ENCA, DRIVETRAIN::RTRANS::ENCB} };

    frc::Solenoid shifter{DRIVETRAIN::SOLENOID::PORT};

    bool shift_status = DRIVETRAIN::SOLENOID::DEFAULT;
};