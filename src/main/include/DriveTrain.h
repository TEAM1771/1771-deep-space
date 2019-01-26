#pragma once

#include <ctre/Phoenix.h>
#include <Transmission.h>
#include <Constants.h>

class DriveTrain {
public:
    // Why are you so insistant on not using the default constructor?
    void tank(double lrate, double rrate);
private:
    Transmission<WPI_TalonSRX> ltrm {{
            {LTRM::A, Reverse}, 
            {LTRM::B, Reverse}
        }},
        rtrm {{
            {RTRM::A, Forward},
            {RTRM::B, Forward}
        }};
};