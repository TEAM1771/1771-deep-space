#include <Jacks.h>

Jacks::Jacks() {}

void Jacks::init() {
    front_left.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 30);
    front_right.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 30);
    back.ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 30);

    front_left.SetSensorPhase(true);
    front_right.SetSensorPhase(true);
    back.SetSensorPhase(true);

    front_left.Config_kP(0, JACKS::FRONT_LEFT::P, 30);
    front_left.Config_kI(0, JACKS::FRONT_LEFT::I, 30);
    front_left.Config_kD(0, JACKS::FRONT_LEFT::D, 30);

    front_right.Config_kP(0, JACKS::FRONT_RIGHT::P, 30);
    front_right.Config_kI(0, JACKS::FRONT_RIGHT::I, 30);
    front_right.Config_kD(0, JACKS::FRONT_RIGHT::D, 30);

    back.Config_kP(0, JACKS::BACK::P, 30);
    back.Config_kI(0, JACKS::BACK::I, 30);
    back.Config_kD(0, JACKS::BACK::D, 30);
}

void Jacks::raise() {
    front_left.Set(ControlMode::Position, JACKS::POSITION::RAISED);
    front_right.Set(ControlMode::Position, JACKS::POSITION::RAISED);
    back.Set(ControlMode::Position, JACKS::POSITION::RAISED);
}

void Jacks::raiseFront(){
    front_left.Set(ControlMode::Position, JACKS::POSITION::RAISED);
    front_right.Set(ControlMode::Position, JACKS::POSITION::RAISED);
    // No setting for back. This should assure that even if this is enabled 
    // while the bot has jacks raised it won't lower the back and tip us over.
}

void Jacks::lower() {
    front_left.Set(ControlMode::Position, JACKS::POSITION::LOWERED);
    front_right.Set(ControlMode::Position, JACKS::POSITION::LOWERED);
    back.Set(ControlMode::Position, JACKS::POSITION::LOWERED);
}

void Jacks::drive(double rate) {
    driver.Set(ControlMode::PercentOutput, rate);
}