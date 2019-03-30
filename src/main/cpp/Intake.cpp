#include <Intake.h>

#include <iostream>

Intake::Intake() {
    pivot.SetSelectedSensorPosition(0);

    pivot.SetStatusFramePeriod(StatusFrameEnhanced::Status_13_Base_PIDF0, 10, timeoutPID);
    pivot.SetStatusFramePeriod(StatusFrameEnhanced::Status_10_MotionMagic, 10, timeoutPID);

    pivot.Config_kP(0, INTAKE::PIVOT::P, timeoutPID);
    pivot.Config_kI(0, INTAKE::PIVOT::I, timeoutPID);
    pivot.Config_kD(0, INTAKE::PIVOT::D, timeoutPID);
    pivot.Config_kF(0, INTAKE::PIVOT::F, timeoutPID);

    pivot.ConfigPeakOutputForward(0.7);
    pivot.ConfigPeakOutputReverse(-0.3);
    pivot.ConfigNominalOutputForward(0);
    pivot.ConfigNominalOutputReverse(0);

    setPosition(INTAKE::PIVOT::CARRY_POS);
}

Intake::Demogorgon::Demogorgon() {  
    demogorgon_obj.Set(INTAKE::DEMOGORGON::DEFAULT_STATE);
}

void Intake::setPosition(INTAKE::PIVOT::POSITIONS p){
    if(curpos != p)
        pivot.Set(ControlMode::Position, curpos = p);
}

INTAKE::PIVOT::POSITIONS Intake::getPosition(){
    return curpos;
}

void Intake::update(){
    std::cout << "Pivot: " << pivot.GetSelectedSensorPosition() << "\n";
}

// Nobody checks what I put in the commit they just read the message
// look at this real change in code that does real things

void Intake::Demogorgon::Set(bool rgon) {
    demogorgon_obj.Set(rgon != INTAKE::DEMOGORGON::DEFAULT_STATE);
}