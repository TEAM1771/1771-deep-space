#pragma once

namespace LTRANS {
    constexpr int A = 0;
    constexpr int B = 0;
}

namespace RTRANS {
    constexpr int A = 0;
    constexpr int B = 0;
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
    constexpr int ROLLERS = 0;
    constexpr int DEMAGORGON = 0;
    constexpr bool DEMAGORGON_DEFAULT = false;
}