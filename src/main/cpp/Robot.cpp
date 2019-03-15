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

  driveTrain.init();
  jacks.init();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}


/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  canJack = false;
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  StandardDrive();
}

void Robot::DisabledPeriodic() {
  //jacks.update();
  //intake.update();
  //elevator.update();
  driveTrain.update();
}

void Robot::TeleopInit() {
  canJack = true;
}

void Robot::StandardDrive() {
  driveTrain.update();
  jacks.raise();
  // Standard Tank Drive
  driveTrain.tank(-left.GetY(), -right.GetY());

  // Demogorgon
  intake.demogorgon.Set(other.GetRawButton(JOY::OTHER::DEMOGORGON));

  // Jack off
  if(canJack && right.GetRawButton(JOY::RIGHT::JACK_OFF) && left.GetRawButton(JOY::LEFT::JACK_OFF)){
    jackOff = true;
    jacks.lower();
    driveTrain.tank(0.35, 0.35);
    jacks.drive(0.4);

    timer.Reset();
    timer.Start();
  }else if(canJack && right.GetRawButton(JOY::RIGHT::JACK_OFF_HAB2) && left.GetRawButton(JOY::LEFT::JACK_OFF_HAB2)){
    jackOff = true;
    jacks.lowerHAB2();
    driveTrain.tank(0.35, 0.35);
    jacks.drive(0.4);

    timer.Reset();
    timer.Start();
  }else if(canJack && right.GetRawButton(JOY::RIGHT::JACK_OFF_HAB2to3) && left.GetRawButton(JOY::LEFT::JACK_OFF_HAB2to3)){
    jackOffManual = true;
    jacks.lowerHAB2to3();
    driveTrain.tank(0.35, 0.35);
    jacks.drive(0.4);

    timer.Reset();
    timer.Start();
  }

  bool moving = false;
  if(other.GetRawButton(JOY::OTHER::ELVTR_POS_HIGH)){
    elevator.setPosition(ELVTR::POSITION::HIGH);
    moving = true;
  }else if(other.GetRawButton(JOY::OTHER::ELVTR_POS_MID)){
    elevator.setPosition(ELVTR::POSITION::CARGO);
    moving = true;
  }else if(other.GetRawButton(JOY::OTHER::ELVTR_POS_LOW)){
    elevator.setPosition(ELVTR::POSITION::LOW);
    moving = true;
  }else if(other.GetRawButton(JOY::OTHER::ELVTR_POS_HATCH)){
    elevator.setPosition(ELVTR::POSITION::HATCH);
    moving = true;
  }

  if(!moving){
    if(other.GetRawButton(JOY::OTHER::INTAKE_HIGH)){
      intake.setPosition(INTAKE::PIVOT::HIGH_POS);
    }else if(other.GetRawButton(JOY::OTHER::INTAKE_MID)){
      intake.setPosition(INTAKE::PIVOT::CARRY_POS);
    }else if(other.GetRawButton(JOY::OTHER::INTAKE_LOW)){
      intake.setPosition(INTAKE::PIVOT::LOW_POS);
    }
  }else{
    intake.setPosition(INTAKE::PIVOT::CARRY_POS);
  }
  //intake.update();
  
  if(other.GetRawButton(JOY::OTHER::ROLLERS_IN)){
    intake.rollers.Set(ControlMode::PercentOutput, 1);
    //intake.setPosition(INTAKE::PIVOT::POSITIONS::LOW_POS);
  }else if(other.GetRawButton(JOY::OTHER::ROLLERS_OUT)){
    intake.rollers.Set(ControlMode::PercentOutput, -1);
  }else{
    intake.rollers.Set(ControlMode::PercentOutput, 0);
    //intake.setPosition(pivotPos);
  }

  //std::cout << "rate:" << rate << "\n";

  //elevator.set(other.GetY());
  elevator.update();
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
  }
}

void Robot::TeleopPeriodic() {
  if(jackOffManual)
    JackOffManual();
  else if(jackOff)
    JackOffDrive();
  else
    StandardDrive();
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
