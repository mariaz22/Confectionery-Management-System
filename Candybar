#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "Prajitura.h"

class Candybar {
private:
    int id;
    static int nextId;
    std::unordered_map<int, std::vector<std::pair<std::shared_ptr<Prajitura>, int>>> comanda;
public:
    Candybar();

    void adaugaProdus(std::shared_ptr<Prajitura> produs, int cantitate, int id);
    static int genereazaId();
    Candybar& operator=(const Candybar& c);
    float calculeazaTimpTotalPreparare(int id) const;
    float calculeazaCaloriiTotal(int id) const;
    float calculeazaPretTotal(int id) const;
    void afiseazaDetalii(int id) const;
};
