#include <Jacks.h>

Jacks::Jacks() {}

void Jacks::init() {
    front_left.SetSensorPhase(true);
    front_right.SetSensorPhase(true);
    back.SetSensorPhase(true);

    front_left.SetInverted(1);
    front_right.SetInverted(0);
    back.SetInverted(0);

    front_left.Config_kP(0, JACKS::FRONT_LEFT::P, timeoutPID);
    front_left.Config_kI(0, JACKS::FRONT_LEFT::I, timeoutPID);
    front_left.Config_kD(0, JACKS::FRONT_LEFT::D, timeoutPID);

    front_right.Config_kP(0, JACKS::FRONT_RIGHT::P, timeoutPID);
    front_right.Config_kI(0, JACKS::FRONT_RIGHT::I, timeoutPID);
    front_right.Config_kD(0, JACKS::FRONT_RIGHT::D, timeoutPID);

    back.Config_kP(0, JACKS::BACK::P, timeoutPID);
    back.Config_kI(0, JACKS::BACK::I, timeoutPID);
    back.Config_kD(0, JACKS::BACK::D, timeoutPID);

    back.SetSelectedSensorPosition(0);
    front_left.SetSelectedSensorPosition(0);
    front_right.SetSelectedSensorPosition(0);

    back.SetNeutralMode(NeutralMode::Brake);
    front_left.SetNeutralMode(NeutralMode::Brake);
    front_right.SetNeutralMode(NeutralMode::Brake);

}

void Jacks::lower() {
    front_left.Set(ControlMode::Position, JACKS::DROP_HEIGHT);
    front_right.Set(ControlMode::Position, JACKS::DROP_HEIGHT);
    back.Set(ControlMode::Position, JACKS::DROP_HEIGHT);
}

void Jacks::raiseFront() {
    front_left.Set(ControlMode::Position, JACKS::FRONT_LEFT::LIFT_HEIGHT);
    front_right.Set(ControlMode::Position, JACKS::FRONT_RIGHT::LIFT_HEIGHT);
    // No setting for back. This should assure that even if this is enabled 
    // while the bot has jacks raised it won't lower the back and tip us over.
}

void Jacks::raise() {
    front_left.Set(ControlMode::Position, JACKS::FRONT_LEFT::LIFT_HEIGHT);
    front_right.Set(ControlMode::Position, JACKS::FRONT_RIGHT::LIFT_HEIGHT);
    back.Set(ControlMode::Position, JACKS::BACK::LIFT_HEIGHT);
}

void Jacks::update() {
    std::cout << back.GetSelectedSensorPosition() << " " << front_left.GetSelectedSensorPosition() << " " << front_right.GetSelectedSensorPosition() << "\n";
}



void Jacks::drive(double rate) {
    driver.Set(ControlMode::PercentOutput, rate);
}