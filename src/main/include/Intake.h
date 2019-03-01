#pragma once

#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>

#include <Constants.h>

class Intake {
public:
    WPI_TalonSRX rollers { INTAKE::ROLLERS::MTR };

    struct Demogorgon
    {
        public:
        Demogorgon();
        void Set(bool rgon);
        private:
        frc::Solenoid demogorgon_obj { INTAKE::DEMOGORGON::PORT };
    } demogorgon;
};