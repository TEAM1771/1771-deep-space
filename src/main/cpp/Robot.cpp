/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  ultrasonic.SetAutomaticMode(true);
}

void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  canJack = false;
}

void Robot::AutonomousPeriodic() {
  StandardDrive();
}

void Robot::DisabledPeriodic() {
  debug();
}

void Robot::TeleopInit() {
  canJack = true;
}

void Robot::TeleopPeriodic() {
  debug();
  if(jackOffManual)
    JackOffManual();
  else if(jackOffTimed)
    JackOffDriveTIMED();
  else if(jackOff)
    JackOffDrive();
  else
    StandardDrive();
}

void Robot::TestPeriodic() {}

/* * * * * * * * * * * *
 *  CUSTOM  FUNCTIONS  *
 * * * * * * * * * * * */

void Robot::debug() {
  //driveTrain.update();
  std::cout << "Ultrasonic Reading: " << ultrasonic.GetRangeInches() << "\n";
  //elevator.update();
  //intake.update();
  //jacks.update();
}

void Robot::StandardDrive() {
  // Standard Tank Drive
  driveTrain.tank(-left.GetY(), -right.GetY());

  ElevatorManagement();
  IntakeManagement();
  JackManagement();

}

void Robot::IntakeManagement() {
  // Demogorgon
  intake.demogorgon.Set(!other.GetRawButton(JOY::OTHER::DEMOGORGON));

  // Set intake to appropriate position, unless elevator is moving, then stay in safe carry position
  if(other.GetRawButton(JOY::OTHER::INTAKE_HIGH)){
    intake.setPosition(INTAKE::PIVOT::HIGH_POS);
  }else if(other.GetRawButton(JOY::OTHER::INTAKE_MID)){
    intake.setPosition(INTAKE::PIVOT::CARRY_POS);
  }else if(other.GetRawButton(JOY::OTHER::INTAKE_LOW)){
    intake.setPosition(INTAKE::PIVOT::LOW_POS);
  }

  if(elevatorMoving && intake.getPosition() == INTAKE::PIVOT::HIGH_POS)
    intake.setPosition(INTAKE::PIVOT::CARRY_POS);
  
  
  // Intake/outtake
  if(other.GetRawButton(JOY::OTHER::ROLLERS_IN)){
    intake.rollers.Set(ControlMode::PercentOutput, 1);
  }else if(other.GetRawButton(JOY::OTHER::ROLLERS_OUT)){
    intake.rollers.Set(ControlMode::PercentOutput, -1);
  }else{
    intake.rollers.Set(ControlMode::PercentOutput, 0);
  }
}

void Robot::ElevatorManagement() {
  // Set the elevator to the appropriate position and set the "elevatorMoving" to true if it is moving
  elevatorMoving = false;
  if(other.GetRawButton(JOY::OTHER::ELVTR_POS_HIGH)){
    elevator.setPosition(ELVTR::POSITION::HIGH);
    driveTrain.canShift(false);
    elevatorMoving = true;
  }else if(other.GetRawButton(JOY::OTHER::ELVTR_POS_MID)){
    elevator.setPosition(ELVTR::POSITION::CARGO);
    driveTrain.canShift(false);
    elevatorMoving = true;
  }else if(other.GetRawButton(JOY::OTHER::ELVTR_POS_LOW)){
    elevator.setPosition(ELVTR::POSITION::LOW);
    driveTrain.canShift(true);
    elevatorMoving = true;
  }else if(other.GetRawButton(JOY::OTHER::ELVTR_POS_HATCH)){
    elevator.setPosition(ELVTR::POSITION::HATCH);
    driveTrain.canShift(false);
    elevatorMoving = true;
  }
}

void Robot::JackManagement() {
  // Keep the jacks raised when not climbing
  jacks.raise();
  jackStage = 0;

  if(canJack){
    bool const hab1to3 = right.GetRawButton(JOY::RIGHT::JACK_OFF) && left.GetRawButton(JOY::LEFT::JACK_OFF);
    bool const hab1to3TIMED = right.GetRawButton(JOY::RIGHT::JACK_OFF_HAB3TIMED) && left.GetRawButton(JOY::LEFT::JACK_OFF_HAB3TIMED);
    bool const hab1to2 = right.GetRawButton(JOY::RIGHT::JACK_OFF_HAB2) && left.GetRawButton(JOY::LEFT::JACK_OFF_HAB2);
    bool const hab2to3 = right.GetRawButton(JOY::RIGHT::JACK_OFF_HAB2to3) && left.GetRawButton(JOY::LEFT::JACK_OFF_HAB2to3);

    if((jackOff = hab1to3 || hab1to2) || (jackOffTimed = hab1to3TIMED) || (jackOffManual = hab2to3)){
      driveTrain.tank(0.35, 0.35);
      jacks.drive(0.4);

      if(hab1to3)
        jacks.lower();
      else if(hab1to2)
        jacks.lowerHAB2();
      else if(hab1to3TIMED)
        jacks.lower();
      else if(hab2to3)
        jacks.lowerHAB2to3();

      timer.Reset();
      timer.Start();
    }
  }
}


void Robot::JackOffManual() {
  static double time;
  time = timer.Get();

  constexpr double first_stage = 2;
  constexpr double second_stage = first_stage+1.0; //5;

  if(time > first_stage && time <= second_stage){
    driveTrain.tank(0, 0);
    jacks.drive(0);
    jacks.raiseFront();
  }else if(time > second_stage){
    driveTrain.tank(-left.GetY(), -right.GetY());
    jacks.drive((left.GetY()+right.GetY())/2.0+0.1);
    if(left.GetRawButton(JOY::LEFT::SMALL_LIFT_BACK_JACK))
      jacks.raiseBackSmall();
    else if(right.GetRawButton(JOY::RIGHT::SMALL_DROP_BACK_JACK))
      jacks.lowerBackSmall();
  }
}

void Robot::JackOffDrive() {
  
  static double distance;
  static bool frontOverride = false;
  static bool startLiftFront = false;

  frontOverride |= right.GetRawButton(JOY::RIGHT::OVERRIDE_ULTRA_LIFT_FRONT);

  double const time = timer.Get();

  distance = ultrasonic.GetRangeInches();

  if(!startLiftFront && time < .5) return;

  if(distance >= ULTRASONIC::LIFT_FRONT_DIST){
    //jacks.lower();
    driveTrain.tank(0.35, 0.35);
    jacks.drive(0.4);
  }else if((distance <= ULTRASONIC::LIFT_FRONT_DIST && distance >= ULTRASONIC::REAR_LIFT_DIST) || frontOverride){
    
    if(!startLiftFront){
      startLiftFront = true;
      timer.Reset();
      timer.Start();
    }

    jacks.raiseFront();
    if(time < 0.85){
      jacks.drive(0);
      driveTrain.tank(0,0);
    }else{
      jacks.drive(1);
      driveTrain.tank(0.35, 0.35);
    }
  }else if(distance <= ULTRASONIC::REAR_LIFT_DIST && distance >= ULTRASONIC::SAFE_ON){
    jacks.drive(0);
    jacks.raise();
  }else if(distance <= ULTRASONIC::SAFE_ON){
    jacks.drive(0);
    jackOff = false;
    startLiftFront = false;
  }
}

void Robot::JackOffDriveTIMED() {
  static double time;
  time = timer.Get();    

  constexpr double first_stage = 2;
  constexpr double second_stage = first_stage+2.0; //5;
  constexpr double third_stage = second_stage+1.5; //6.5;
  constexpr double fourth_stage = third_stage+0.5; //7.5;
  constexpr double fifth_stage = fourth_stage+1.0; //8.5;

  if(time > first_stage && time <= second_stage){
    driveTrain.tank(0, 0);
    jacks.raiseFront();
  }else if(time > second_stage && time <= third_stage){
    driveTrain.tank(0.25, 0.25);
    jacks.drive(0.35);
  }else if(time > third_stage && time <= fourth_stage){
    jacks.raise();
    driveTrain.tank(0.25,0.25);
    jacks.drive(0.35);
  }else if(time > fourth_stage && time <= fifth_stage){
    driveTrain.tank(0.25,0.25);
    jacks.drive(0);
  }else if(time > fifth_stage){
    jackOff = false;
    jackOffTimed = false;
  }
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
