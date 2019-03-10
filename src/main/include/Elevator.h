#pragma once

#include <ctre/Phoenix.h>

#include <Constants.h>

class Elevator {
public:

    Elevator();
    void setPosition(ELVTR::POSITION pos);
    ELVTR::POSITION getPosition();
    void update();

    void set(double rate);

private:
    WPI_TalonSRX elevatorMotor{ELVTR::MTR};
    ELVTR::POSITION targetPos = ELVTR::POSITION::DEFAULT;
};