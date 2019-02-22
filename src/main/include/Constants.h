#pragma once

namespace DRIVETRAIN {
    namespace LTRANS {
        constexpr int MTRA = 1;
        constexpr int MTRB = 5;
    }

    namespace RTRANS {
        constexpr int MTRA = 10;
        constexpr int MTRB = 3;
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
    constexpr int MTR = 0;

    constexpr double P = 0;
    constexpr double I = 0;
    constexpr double D = 0;

    enum POSITION {
        DEFAULT = 0,
        LOW = 0,
        MID = 0,
        HIGH = 0,
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
    }
}

namespace INTAKE {
    namespace ROLLERS {
        constexpr int MTR = 0;
        constexpr double IN_SPEED = 0;
        constexpr double OUT_SPEED = 0;
    }

    namespace DEMOGORGON {
        constexpr int PORT = 0;
        constexpr bool IN = true;
        constexpr bool OUT = !IN;
        constexpr bool DEFAULT_STATE = IN;
    }
}

namespace JACKS {
    namespace FRONT_LEFT {
        constexpr int PORT = 0;
        constexpr double P = 0.0;
        constexpr double I = 0.0;
        constexpr double D = 0.0;
    }

    namespace FRONT_RIGHT {
        constexpr int PORT = 0;
        constexpr double P = 0.0;
        constexpr double I = 0.0;
        constexpr double D = 0.0;
    }

    namespace BACK {
        constexpr int PORT = 0;
        constexpr double P = 0.0;
        constexpr double I = 0.0;
        constexpr double D = 0.0;
    }

    constexpr int DRIVER_PORT = 0;

    enum POSITION {
        RAISED = 0,
        LOWERED = 0,
    };

}