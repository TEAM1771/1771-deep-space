#include <DriveTrain.h>

DriveTrain::DriveTrain() : 
    ltrm({
        {DRIVETRAIN::LTRANS::MTRA, Direction::Reverse}, 
        {DRIVETRAIN::LTRANS::MTRB, Direction::Reverse}
    }),
    rtrm({
        {DRIVETRAIN::RTRANS::MTRA, Direction::Forward},
        {DRIVETRAIN::RTRANS::MTRB, Direction::Forward}
    }),
    shifter(DRIVETRAIN::SOLENOID_PORT) { }

void DriveTrain::tank(double lrate, double rrate) {
    ltrm->Set(ControlMode::PercentOutput, lrate);
    rtrm->Set(ControlMode::PercentOutput, rrate);
}

void DriveTrain::shift(bool ornottoshift){
    shifter.Set(ornottoshift);
}