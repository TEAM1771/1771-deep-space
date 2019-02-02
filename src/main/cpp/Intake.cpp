#include <Intake.h>

Intake::Intake() : roller(INTAKE::ROLLERS), demagorgon(INTAKE::DEMAGORGON) { }

void Intake::set(double rate) {
    roller.Set(ControlMode::PercentOutput, rate);
}

void Intake::demago(bool rgon){
    demagorgon.Set(rgon);
}