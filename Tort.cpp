#include "Tort.h"
#include <iostream>

Tort::Tort(const std::string& nume, float gramaj, const std::string& forma, const std::string& eveniment, int timp_preparare_crema, int timp_decorare)
    : Prajitura(nume, gramaj), forma(forma), eveniment(eveniment), timp_preparare_crema(timp_preparare_crema), timp_decorare(timp_decorare) {}

float Tort::calculeazaTimpTotalPreparare() const {
    return timp_preparare_crema+timp_decorare+120;
}

float Tort::calculeazaCaloriiTotal() const {
    if(eveniment=="Aniversare")
        return 50*(gramaj/100);
    return 40*(gramaj/100);
}

float Tort::calculeazaPretTotal() const {
    return 3*(gramaj/100);
}
