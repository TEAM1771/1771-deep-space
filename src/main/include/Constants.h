#pragma once

constexpr int timeoutPID = 10;

namespace ULTRASONIC {
    constexpr int ECHO_PORT = 4;
    constexpr int TRIGGER_PORT = 5;

    constexpr double MAX_DIST = 62.0;
    constexpr double LIFT_FRONT_DIST = 60.05;
    constexpr double REAR_LIFT_DIST = 51.0;
    constexpr double SAFE_ON = 36.0;
    
}

namespace DRIVETRAIN {
    namespace LTRANS {
        constexpr int MTRA = 1;
        constexpr int MTRB = 17;

        constexpr int ENCA = 0;
        constexpr int ENCB = 1;
    }

    namespace RTRANS {
        constexpr int MTRA = 11;
        constexpr int MTRB = 12;

        constexpr int ENCA = 2;
        constexpr int ENCB = 3;
    }


    namespace SOLENOID{
        constexpr int PORT = 0;

        constexpr bool SHIFT_UP = true;
        constexpr bool SHIFT_DOWN = !SHIFT_UP;
        constexpr bool DEFAULT = SHIFT_DOWN;

        constexpr int SHIFT_UP_SPEED = 8000; // 2900 in 2016
        constexpr int SHIFT_DOWN_SPEED = 7999; // 2200 in 2016
    }
}

namespace ELVTR {
    constexpr int MTR = 2;  
                              // Old Values for non-cragged elevator
    constexpr double P = 0.2; // 0.1 
    constexpr double I = 0.0; //0.0
    constexpr double D = 0.0; //0.0
    constexpr double F = 0.0; //0.0

    constexpr double VRAMP = 0.2;

    enum POSITION {
        DEFAULT = 0,
        LOW = 150,
        HATCH = 5350,
        CARGO = 16000,
        HIGH = 25000,
    };
    //OLD
    // enum POSITION {
    //     DEFAULT = 0,
    //     LOW = 150,
    //     HATCH = 7650,
    //     CARGO = 16000,
    //     HIGH = 25600,
    // };
}

namespace JOY {
    namespace LEFT {
        constexpr int PORT = 0;
        constexpr int JACK_OFF = 1;
        constexpr int JACK_OFF_HAB2 = 3;
        constexpr int JACK_OFF_HAB3TIMED = 8;
        constexpr int JACK_OFF_HAB2to3 = 4;
        constexpr int SMALL_LIFT_BACK_JACK = 6;
    }

    namespace RIGHT {
        constexpr int PORT = 1;
        constexpr int JACK_OFF = 1;
        constexpr int JACK_OFF_HAB2 = 3;
        constexpr int JACK_OFF_HAB3TIMED = 9;
        constexpr int JACK_OFF_HAB2to3 = 5;
        constexpr int SMALL_DROP_BACK_JACK = 11;
    }

    namespace OTHER {
        constexpr int PORT = 2;
        constexpr int DEMOGORGON = 1;
        constexpr int ROLLERS_IN = 5;
        constexpr int ROLLERS_OUT = 6;
        
        constexpr int INTAKE_HIGH = 7;
        constexpr int INTAKE_MID = 9;
        constexpr int INTAKE_LOW = 11;

        constexpr int ELVTR_POS_LOW = 12;
        constexpr int ELVTR_POS_MID = 10;
        constexpr int ELVTR_POS_HIGH = 8;
        constexpr int ELVTR_POS_HATCH = 2;
    }
}

namespace INTAKE {
    namespace PIVOT {
        constexpr int MTR = 7;
        enum POSITIONS {
            LOW_POS = -3100,
            //OLDCARRY_POS = -440,
            CARRY_POS = -680,
            HIGH_POS = 0,
        };

        constexpr double P = 1.8;
        constexpr double I = 0.00003;
        constexpr double D = 0.2;
        constexpr double F = 0.0;

    }

    namespace ROLLERS {
        constexpr int MTR = 6;
        constexpr double IN_SPEED = 0;
        constexpr double OUT_SPEED = 0;
    }

    namespace DEMOGORGON {
        constexpr int PORT = 1;
        constexpr bool IN = true;
        constexpr bool OUT = !IN;
        constexpr bool DEFAULT_STATE = IN;
    }
}

namespace JACKS {
    namespace FRONT_LEFT {
        constexpr int PORT = 4;
        constexpr double P = 0.4;
        constexpr double I = 0.0;
        constexpr double D = 0.0;

        constexpr int LIFT_HEIGHT = -2107;
    }

    namespace FRONT_RIGHT {
        constexpr int PORT = 9;
        constexpr double P = 0.4;
        constexpr double I = 0.0;
        constexpr double D = 0.0;

        constexpr int LIFT_HEIGHT = -2149;
    }

    namespace BACK {
        constexpr int PORT = 5;
        constexpr double P = 0.4;
        constexpr double I = 0.0;
        constexpr double D = 0.0;

        constexpr int LIFT_HEIGHT = -1282;
        constexpr int DROP_HEIGHT = -12*JACKS::FRONT_LEFT::LIFT_HEIGHT;

    }

    constexpr int DROP_HEIGHT = -13*JACKS::FRONT_LEFT::LIFT_HEIGHT;

    constexpr int DRIVER_PORT = 10;

}