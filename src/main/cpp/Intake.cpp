#include <Intake.h>

Intake::Intake() : roller(INTAKE::ROLLERS_PORT), demagorgon(INTAKE::DEMAGORGON_PORT) { }

void Intake::set(double rate) {
    roller.Set(ControlMode::PercentOutput, rate);
}

void Intake::demago(bool rgon){
    demagorgon.Set(rgon);
}