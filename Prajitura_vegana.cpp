include "Prajitura_Vegana.h"
#include <iostream>

PrajituraVegana::PrajituraVegana(const std::string& nume, float gramaj, float timp_coacere, int timp_amestec_ingrediente)
    : Prajitura(nume, gramaj), timp_coacere(timp_coacere), timp_amestec_ingrediente(timp_amestec_ingrediente)  {}

float PrajituraVegana::calculeazaTimpTotalPreparare() const {
    return timp_coacere+timp_amestec_ingrediente+15;
}

float PrajituraVegana::calculeazaCaloriiTotal() const {
    return 100 * (gramaj / 100);
}

float PrajituraVegana::calculeazaPretTotal() const {
    return 2,50*(gramaj/100);
}
