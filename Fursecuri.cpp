#include "Fursecuri.h"
#include <iostream>

Fursecuri::Fursecuri(const std::string& nume, float gramaj, const std::string& forma, int timp_glazurare, int timp_amestec)
    : Prajitura(nume, gramaj), forma(forma), timp_glazurare(timp_glazurare), timp_amestec(timp_amestec) {}

float Fursecuri::calculeazaTimpTotalPreparare() const {
    return timp_glazurare+timp_amestec+20;
}

float Fursecuri::calculeazaCaloriiTotal() const {
    return 120*(gramaj/100);
}

float Fursecuri::calculeazaPretTotal() const {
    if(forma=="Rotund")
       return 2.5*(gramaj/100);
    return 4*(gramaj/100);
}
