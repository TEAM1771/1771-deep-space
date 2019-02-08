#include <Intake.h>

Intake::Intake(){ }

void Intake::set(double rate) {
    roller.Set(ControlMode::PercentOutput, rate);
}

void Intake::demago(bool rgon){
    demagorgon.Set(rgon);
}