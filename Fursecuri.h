#pragma once
#include "Prajitura.h"

class Fursecuri : public Prajitura {
private:
    std::string forma;
    int timp_glazurare;
    int timp_amestec;
public:
    Fursecuri(const std::string& nume, float gramaj, const std::string& forma, int timp_glazurare, int timp_amestec);
    virtual ~Fursecuri() {}

    virtual float calculeazaTimpTotalPreparare() const override;
    virtual float calculeazaCaloriiTotal() const override;
    virtual float calculeazaPretTotal() const override;
};


