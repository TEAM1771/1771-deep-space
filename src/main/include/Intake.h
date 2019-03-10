#pragma once

#include <frc/Solenoid.h>
#include <ctre/Phoenix.h>

#include <Constants.h>

class Intake {
public:
    WPI_TalonSRX rollers { INTAKE::ROLLERS::MTR };
    Intake();

    void setPosition(INTAKE::PIVOT::POSITIONS p);
    INTAKE::PIVOT::POSITIONS getPosition();
    void update();

    struct Demogorgon
    {
        public:
        Demogorgon();
        void Set(bool rgon);
        private:
        frc::Solenoid demogorgon_obj { INTAKE::DEMOGORGON::PORT };
    } demogorgon;

private:
    WPI_TalonSRX pivot { INTAKE::PIVOT::MTR };
    INTAKE::PIVOT::POSITIONS curpos;
};