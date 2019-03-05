#pragma once

constexpr int timeoutPID = 10;

namespace DRIVETRAIN {
    namespace LTRANS {
        constexpr int MTRA = 1;
        constexpr int MTRB = 2;

        constexpr int ENCA = 0;
        constexpr int ENCB = 1;
    }

    namespace RTRANS {
        constexpr int MTRA = 3;
        constexpr int MTRB = 4;

        constexpr int ENCA = 2;
        constexpr int ENCB = 3;
    }


    namespace SOLENOID{
        constexpr int PORT = 0;

        constexpr bool SHIFT_UP = true;
        constexpr bool SHIFT_DOWN = !SHIFT_UP;
        constexpr bool DEFAULT = SHIFT_DOWN;

        constexpr int SHIFT_UP_SPEED = 1300; // 2900 in 2016
        constexpr int SHIFT_DOWN_SPEED = 900; // 2200 in 2016
    }
}

namespace ELVTR {
    constexpr int MTR = 8;
                              // Old Values for non-cragged elevator
    constexpr double P = 0.0; //0.4;
    constexpr double I = 0.0; //0.0;
    constexpr double D = 0.0; //20.5;
    constexpr double F = 0.0; //0.0;

    constexpr double VRAMP = 0.2;

    enum POSITION {
        DEFAULT = 0,
        LOW = 100,
        MID = 12231,
        HIGH = 22463,
    };
}

namespace JOY {
    namespace LEFT {
        constexpr int PORT = 0;
    }

    namespace RIGHT {
        constexpr int PORT = 1;
    }

    namespace OTHER {
        constexpr int PORT = 2;
        constexpr int DEMOGORGON = 0;
        constexpr int ROLLERS = 0;
        
        constexpr int JACK_OFF_A = 3;
        constexpr int JACK_OFF_B = 4;

        constexpr int JACK_OFF_STAGE2_A = 5;
        constexpr int JACK_OFF_STAGE2_B = 6;

        constexpr int ELVTR_POS_LOW = 12;
        constexpr int ELVTR_POS_MID = 10;
        constexpr int ELVTR_POS_HIGH = 8;
    }
}

namespace INTAKE {
    namespace PIVOT {
        constexpr int MTR = 11;
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
        constexpr double P = 0.15;
        constexpr double I = 0.0;
        constexpr double D = 0.0;

        constexpr int LIFT_HEIGHT = -2107;
    }

    namespace FRONT_RIGHT {
        constexpr int PORT = 8;
        constexpr double P = 0.15;
        constexpr double I = 0.0;
        constexpr double D = 0.0;

        constexpr int LIFT_HEIGHT = -2149;
    }

    namespace BACK {
        constexpr int PORT = 5;
        constexpr double P = 0.15;
        constexpr double I = 0.0;
        constexpr double D = 0.0;

        constexpr int LIFT_HEIGHT = -1282;

    }

    constexpr int DROP_HEIGHT = -13*JACKS::FRONT_LEFT::LIFT_HEIGHT;

    constexpr int DRIVER_PORT = 10;

}