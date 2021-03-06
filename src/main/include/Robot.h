/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h>
#include <frc/Timer.h>
#include <frc/Ultrasonic.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

#include <rev/CANSparkMax.h>

#include <DriveTrain.h>
#include <Intake.h>
#include <Jacks.h>
#include <Elevator.h>

class Robot : public frc::TimedRobot {
public:
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
    void DisabledPeriodic() override;

private:
    frc::SendableChooser<std::string> m_chooser;
    const std::string kAutoNameDefault = "Default";
    const std::string kAutoNameCustom = "My Auto";
    std::string m_autoSelected;

    DriveTrain driveTrain{};
    Intake intake{};
    Jacks jacks{};
    Elevator elevator{};
    frc::Joystick left{JOY::LEFT::PORT}, right{JOY::RIGHT::PORT}, other{JOY::OTHER::PORT};

    frc::Timer timer{};
    frc::Ultrasonic ultrasonic{ULTRASONIC::ECHO_PORT, ULTRASONIC::TRIGGER_PORT};

    std::shared_ptr<NetworkTable> table;

    // don't laugh
    bool jackOff = false; // lol
    bool jackOffManual = false;
    bool jackOffTimed = false;
    bool canJack = false;
    bool elevatorMoving = false;
    bool inAuton = true;
    int jackStage = 0;
    bool frontLiftStarted = false;

    void JackManagement();
    void ElevatorManagement();
    void IntakeManagement();

    void StandardDrive();
    void JackOffDrive(); // DONT LAUGH
                        // LOL
    void JackOffDriveTIMED();
    void JackOffManual();

    void debug();

};
