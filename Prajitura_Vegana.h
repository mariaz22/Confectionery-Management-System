#pragma once
#include "Prajitura.h"

class PrajituraVegana : public Prajitura {
private:
    float timp_coacere;
    int timp_amestec_ingrediente;
public:
    PrajituraVegana(const std::string& nume, float gramaj, float timp_coacere, int timp_amestec_ingrediente);
    virtual ~PrajituraVegana() {}

    virtual float calculeazaTimpTotalPreparare() const override;
    virtual float calculeazaCaloriiTotal() const override;
    virtual float calculeazaPretTotal() const override;
};
