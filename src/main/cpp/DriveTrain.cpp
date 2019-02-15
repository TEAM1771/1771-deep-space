#include <DriveTrain.h>

DriveTrain::DriveTrain(){
    shifter.Set(DRIVETRAIN::SOLENOID::DEFAULT);
}

void DriveTrain::tank(double lrate, double rrate) {
    ltrm->Set(ControlMode::PercentOutput, lrate);
    rtrm->Set(ControlMode::PercentOutput, rrate);

    double avgVelocity = (ltrm->GetSelectedSensorVelocity()+rtrm->GetSelectedSensorVelocity())/2.0;
    if(shift_status == DRIVETRAIN::SOLENOID::SHIFT_DOWN && avgVelocity >= DRIVETRAIN::SOLENOID::SHIFT_UP_SPEED)
        shift(DRIVETRAIN::SOLENOID::SHIFT_UP);
    else if(shift_status == DRIVETRAIN::SOLENOID::SHIFT_UP && avgVelocity <= DRIVETRAIN::SOLENOID::SHIFT_DOWN_SPEED)
        shift(DRIVETRAIN::SOLENOID::SHIFT_DOWN);
}

void DriveTrain::shift(bool ornottoshift){
    shifter.Set(ornottoshift);
    shift_status = ornottoshift;
}