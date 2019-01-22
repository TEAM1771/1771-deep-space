#include <DriveTrain.h>

DriveTrain::DriveTrain() : 
    ltrm({
        {LTRM::A, Direction::Reverse}, 
        {LTRM::B, Direction::Reverse}
    }),
    rtrm({
        {RTRM::A, Direction::Forward},
        {RTRM::B, Direction::Forward}
    }) { }

void DriveTrain::tank(double lrate, double rrate) {
    ltrm.Set(ControlMode::PercentOutput, lrate);
    rtrm.Set(ControlMode::PercentOutput, rrate);
}