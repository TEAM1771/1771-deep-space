#include <Intake.h>

Intake::Demagorgon::Demagorgon() {
    demagorgon_obj.Set(INTAKE::DEMAGORGON::DEFAULT_STATE);
}

void Intake::Demagorgon::Set(bool rgon) {
    demagorgon_obj.Set(rgon);
}