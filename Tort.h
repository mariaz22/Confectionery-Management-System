#pragma once
#include "Prajitura.h"

class Tort : public Prajitura {
private:
    std::string forma;
    std::string eveniment;
    int timp_preparare_crema;// *
    int timp_decorare;

public:
    Tort(const std::string& nume, float gramaj, const std::string& forma, const std::string& eveniment, int timp_preparare_crema, int timp_decorare);
    virtual ~Tort() {}

    virtual float calculeazaTimpTotalPreparare() const override;
    virtual float calculeazaCaloriiTotal() const override;
    virtual float calculeazaPretTotal() const override;
};

