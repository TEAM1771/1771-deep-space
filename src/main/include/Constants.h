#pragma once

namespace DRIVETRAIN {
    namespace LTRANS {
        constexpr int MTRA = 0;
        constexpr int MTRB = 0;
    }

    namespace RTRANS {
        constexpr int MTRA = 0;
        constexpr int MTRB = 0;
    }


    namespace SOLENOID{
        constexpr int PORT = 0;

        constexpr bool SHIFT_UP = true;
        constexpr bool SHIFT_DOWN = !SHIFT_UP;
        constexpr bool DEFAULT = false;

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
        constexpr int PORT = 0;
    }

    namespace OTHER {
        constexpr int PORT = 0;
        constexpr int DEMAGORGON = 0;
        constexpr int ROLLERS = 0;
    }
}

namespace INTAKE {
    constexpr int ROLLERS_PORT = 0;
    constexpr int DEMAGORGON_PORT = 0;
    constexpr bool DEMAGORGON_DEFAULT_STATE = false;
}