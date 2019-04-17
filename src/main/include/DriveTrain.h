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

    void canShift(bool status);

    void update();

private:
    Transmission<rev::CANSparkMax> ltrm{{
    // Transmission<WPI_TalonSRX> ltrm{{
        {DRIVETRAIN::LTRANS::MTRA, Direction::Reverse}, 
        {DRIVETRAIN::LTRANS::MTRB, Direction::Reverse}
    }, {DRIVETRAIN::LTRANS::ENCA, DRIVETRAIN::LTRANS::ENCB} }, 
    rtrm{{
        {DRIVETRAIN::RTRANS::MTRA, Direction::Forward},
        {DRIVETRAIN::RTRANS::MTRB, Direction::Forward}
    }, {DRIVETRAIN::RTRANS::ENCA, DRIVETRAIN::RTRANS::ENCB} };


    frc::Solenoid shifter{DRIVETRAIN::SOLENOID::PORT};

    bool shift_status = DRIVETRAIN::SOLENOID::DEFAULT;
    bool can_shift = true;
};