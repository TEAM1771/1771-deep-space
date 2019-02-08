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
    shifter(DRIVETRAIN::SOLENOID::PORT) {

    shifter.Set(DRIVETRAIN::SOLENOID::DEFAULT);
}

void DriveTrain::tank(double lrate, double rrate) {
    ltrm->Set(ControlMode::PercentOutput, lrate);
    rtrm->Set(ControlMode::PercentOutput, rrate);

    double avgVelocity = (ltrm->GetSelectedSensorPosition()+rtrm->GetSelectedSensorPosition())/2.0;
    if(avgVelocity >= DRIVETRAIN::SOLENOID::SHIFT_UP_SPEED && shift_status == DRIVETRAIN::SOLENOID::SHIFT_DOWN)
        shift(DRIVETRAIN::SOLENOID::SHIFT_UP);
    else if(avgVelocity <= DRIVETRAIN::SOLENOID::SHIFT_DOWN_SPEED && shift_status == DRIVETRAIN::SOLENOID::SHIFT_UP)
        shift(DRIVETRAIN::SOLENOID::SHIFT_DOWN)
}

void DriveTrain::shift(bool ornottoshift){
    shifter.Set(ornottoshift);
    shift_status = ornottoshift;
}