#pragma once

namespace DRIVETRAIN {
    namespace LTRANS {
        constexpr int MTRA = 5;
        constexpr int MTRB = 1;
    }

    namespace RTRANS {
        constexpr int MTRA = 3;
        constexpr int MTRB = 10;
    }


    namespace SOLENOID{
        constexpr int PORT = 0;

        constexpr bool SHIFT_UP = true;
        constexpr bool SHIFT_DOWN = !SHIFT_UP;
        constexpr bool DEFAULT = SHIFT_DOWN;

        constexpr int SHIFT_UP_SPEED = 2900;
        constexpr int SHIFT_DOWN_SPEED = 2200;
    }
}

namespace ELVTR {
    constexpr int MTR = 0;

    constexpr int P = 0;
    constexpr int I = 0;
    constexpr int D = 0;

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
        constexpr int PORT = 0;
        constexpr int DEMAGORGON = 0;
        constexpr int ROLLERS = 0;
    }
}

namespace INTAKE {
    namespace ROLLERS {
        constexpr int MTR = 0;
        constexpr double IN_SPEED = 0;
        constexpr double OUT_SPEED = 0;
    }

    namespace DEMAGORGON {
        constexpr int PORT = 0;
        constexpr bool IN = true;
        constexpr bool OUT = !IN;
        constexpr bool DEFAULT_STATE = IN;
    }
}