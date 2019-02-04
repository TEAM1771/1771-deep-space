#include <DriveTrain.h>

DriveTrain::DriveTrain() : 
    ltrm({
        {DRIVETRAIN::LTRANS::A, Direction::Reverse}, 
        {DRIVETRAIN::LTRANS::B, Direction::Reverse}
    }),
    rtrm({
        {DRIVETRAIN::RTRANS::A, Direction::Forward},
        {DRIVETRAIN::RTRANS::B, Direction::Forward}
    }),
    shifter(DRIVETRAIN::SOLENOID) { }

void DriveTrain::tank(double lrate, double rrate) {
    ltrm->Set(ControlMode::PercentOutput, lrate);
    rtrm->Set(ControlMode::PercentOutput, rrate);
}

void DriveTrain::shift(bool ornottoshift){
    shifter.Set(ornottoshift);
}