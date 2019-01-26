#include <DriveTrain.h>

void DriveTrain::tank(double const lrate, double const rrate) {
    ltrm->Set(lrate);
    rtrm->Set(rrate);
}