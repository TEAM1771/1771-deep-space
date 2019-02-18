#pragma once

#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>

#include <Constants.h>

class Intake {
public:
    WPI_TalonSRX rollers { INTAKE::ROLLERS::MTR };

    struct Demagorgan
    {
        Demagorgan();
        void Set(bool rgon);
    private:
        frc::Solenoid demagorgon_obj { INTAKE::DEMAGORGON::PORT };
    } demagorgan;
};