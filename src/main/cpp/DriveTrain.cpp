#include <DriveTrain.h>

#include <iostream>

DriveTrain::DriveTrain(){
    shifter.Set(DRIVETRAIN::SOLENOID::DEFAULT);
}

void DriveTrain::init(){
    ltrm->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 30);
    rtrm->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 30);
    ltrm->SetSensorPhase(true);
    rtrm->SetSensorPhase(true);
}

void DriveTrain::update() {
    std::cout << "Left Pos: " << ltrm->GetSelectedSensorPosition() << "  |  Right Pos: " << rtrm->GetSelectedSensorPosition();
    std::cout << "  ---  Left Vel: " << ltrm->GetSelectedSensorVelocity() << "  |  Right Vel: " << rtrm->GetSelectedSensorVelocity() << "\n";
}

void DriveTrain::tank(double lrate, double rrate) {
    ltrm->Set(ControlMode::PercentOutput, lrate);
    rtrm->Set(ControlMode::PercentOutput, rrate);

    double const avgVelocity = (ltrm->GetSelectedSensorVelocity()+rtrm->GetSelectedSensorVelocity())/2.0;
    if(shift_status == DRIVETRAIN::SOLENOID::SHIFT_DOWN && fabs(avgVelocity) >= DRIVETRAIN::SOLENOID::SHIFT_UP_SPEED)
        shift(DRIVETRAIN::SOLENOID::SHIFT_UP);
    else if(shift_status == DRIVETRAIN::SOLENOID::SHIFT_UP && fabs(avgVelocity) <= DRIVETRAIN::SOLENOID::SHIFT_DOWN_SPEED)
        shift(DRIVETRAIN::SOLENOID::SHIFT_DOWN);
}

void DriveTrain::shift(bool ornottoshift){
    shifter.Set(ornottoshift);
    shift_status = ornottoshift;
    std::cout << (ornottoshift == DRIVETRAIN::SOLENOID::SHIFT_UP) ? ("Shift!\n") : ("Unshift!\n");
}

void DriveTrain::shift(){
    shift_status = !shift_status;
    shifter.Set(shift_status);
    std::cout << (shift_status == DRIVETRAIN::SOLENOID::SHIFT_UP) ? ("Shift!\n") : ("Unshift!\n");
}