#pragma once
#include <string>
#include <vector>
#include <memory>

class Prajitura {
protected:
    std::string nume;
    float gramaj;
public:
    Prajitura(const std::string& nume, float gramaj);
    virtual ~Prajitura() {}

    const std::string& getNume() const;
    float getGramaj() const;
    int getCantitate() const;

    virtual float calculeazaTimpTotalPreparare() const=0;
    virtual float calculeazaCaloriiTotal() const=0;
    virtual float calculeazaPretTotal() const=0;
    static void afiseazaStoc(const std::vector<std::shared_ptr<Prajitura>>& stoc);
};

