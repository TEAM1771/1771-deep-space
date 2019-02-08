#pragma once

#include <ctre/Phoenix.h>

#include <Constants.h>


class Elevator {
public:

    Elevator();
    void setPosition(ELVTR::POSITION pos);

private:
    WPI_TalonSRX elevatorMotor{ELVTR::MTR};
    int targetPos = ELVTR::POSITION::DEFAULT;
};