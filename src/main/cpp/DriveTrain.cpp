#include <DriveTrain.h>

DriveTrain::DriveTrain() : 
    ltrm({
        {LTRANS::A, Direction::Reverse}, 
        {LTRANS::B, Direction::Reverse}
    }),
    rtrm({
        {RTRANS::A, Direction::Forward},
        {RTRANS::B, Direction::Forward}
    }) { }

void DriveTrain::tank(double lrate, double rrate) {
    ltrm->Set(ControlMode::PercentOutput, lrate);
    rtrm->Set(ControlMode::PercentOutput, rrate);
}