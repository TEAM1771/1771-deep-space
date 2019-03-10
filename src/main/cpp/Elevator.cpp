#include <Elevator.h>

#include <iostream>

Elevator::Elevator(){
   elevatorMotor.SetSelectedSensorPosition(0);

    elevatorMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, timeoutPID);
    elevatorMotor.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, timeoutPID);

    elevatorMotor.ConfigNominalOutputForward(0, timeoutPID);
    elevatorMotor.ConfigNominalOutputReverse(0, timeoutPID);
    elevatorMotor.ConfigPeakOutputForward(1, timeoutPID);
    elevatorMotor.ConfigPeakOutputReverse(-1, timeoutPID);

    elevatorMotor.Config_kP(0, ELVTR::P, timeoutPID);
    elevatorMotor.Config_kI(0, ELVTR::I, timeoutPID);
    elevatorMotor.Config_kD(0, ELVTR::D, timeoutPID);
    elevatorMotor.Config_kF(0, ELVTR::F, timeoutPID);

    elevatorMotor.SelectProfileSlot(0,0);

    elevatorMotor.ConfigClosedloopRamp(ELVTR::VRAMP, timeoutPID);

    //elevatorMotor.ConfigMotionCruiseVelocity();

    elevatorMotor.SetSelectedSensorPosition(0);
}

void Elevator::update() {
    std::cout << "elevator pos: " << elevatorMotor.GetSelectedSensorPosition() << "\n";
}

void Elevator::set(double rate) {
    elevatorMotor.Set(ControlMode::PercentOutput, rate);
}

void Elevator::setPosition(ELVTR::POSITION pos) {
    if(pos != targetPos)
        elevatorMotor.Set(ControlMode::Position, targetPos = pos);
}

ELVTR::POSITION Elevator::getPosition() {
    return targetPos;
}