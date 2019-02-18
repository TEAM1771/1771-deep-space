#include <Intake.h>

Intake::Demogorgon::Demogorgon() {
    demogorgon_obj.Set(INTAKE::DEMOGORGON::DEFAULT_STATE);
}

void Intake::Demogorgon::Set(bool rgon) {
    demogorgon_obj.Set(rgon != INTAKE::DEMOGORGON::DEFAULT_STATE);
}