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
    namespace POS {
        constexpr int DEFAULT = 0;
        constexpr int LOW = 0;
        constexpr int MID = 0;
        constexpr int HIGH = 0;
    }
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