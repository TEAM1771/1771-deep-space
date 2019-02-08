#include <Elevator.h>

Elevator::Elevator(){ 
    elevatorMotor.Config_kP(0, ELVTR::P);
    elevatorMotor.Config_kI(0, ELVTR::I);
    elevatorMotor.Config_kD(0, ELVTR::D);
}

void Elevator::setPosition(ELVTR::POSITION pos) {
    if(pos > ELVTR::POSITION::HIGH || pos < ELVTR::POSITION::LOW)
        return;

    targetPos = pos;
    elevatorMotor.Set(ControlMode::Position, targetPos);
}