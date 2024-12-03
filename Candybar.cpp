#include "Candybar.h"
#include "Tort.h"
#include "Prajitura_Vegana.h"
#include "Fursecuri.h"
#include <unordered_map>
#include <iostream>

int Candybar::nextId=1;

Candybar::Candybar() {}

Candybar& Candybar::operator=(const Candybar& c) {
    if (this!=&c) {
        comanda=c.comanda;
    }
    return *this;
}

void Candybar::adaugaProdus(std::shared_ptr<Prajitura> produs, int cantitate, int id) {
    comanda[id].push_back(std::make_pair(produs, cantitate));
}

float Candybar::calculeazaTimpTotalPreparare(int id) const {
    float timpTotal=0.0;
    std::unordered_map<int, std::vector<std::pair<std::shared_ptr<Prajitura>, int>>>::const_iterator i = comanda.find(id);
    if (i!=comanda.end()) {
        for (const auto& icomanda : i->second) {
            std::shared_ptr<Tort> tort=std::dynamic_pointer_cast<Tort>(icomanda.first);
            std::shared_ptr<PrajituraVegana> prajituraVegana = std::dynamic_pointer_cast<PrajituraVegana>(icomanda.first);
            std::shared_ptr<Fursecuri> fursecuri=std::dynamic_pointer_cast<Fursecuri>(icomanda.first);
            if (tort) {
                timpTotal+=tort->calculeazaTimpTotalPreparare()*icomanda.second;
            } else if (prajituraVegana) {
                timpTotal+=prajituraVegana->calculeazaTimpTotalPreparare()*icomanda.second;
            } else if (fursecuri) {
                timpTotal+=fursecuri->calculeazaTimpTotalPreparare()*icomanda.second;
            }
        }
    } else {
        std::cout<<"Comanda cu ID-ul "<<id<<" nu exista!"<<std::endl;
    }
    return timpTotal;
}

float Candybar::calculeazaCaloriiTotal(int id) const {
    float caloriiTotal=0.0;
    std::unordered_map<int, std::vector<std::pair<std::shared_ptr<Prajitura>, int>>>::const_iterator i=comanda.find(id);
    if (i != comanda.end()) {
        for (const auto& icomanda : i->second) {
            std::shared_ptr<Tort> tort=std::dynamic_pointer_cast<Tort>(icomanda.first);
            std::shared_ptr<PrajituraVegana> prajituraVegana=std::dynamic_pointer_cast<PrajituraVegana>(icomanda.first);
            std::shared_ptr<Fursecuri> fursecuri=std::dynamic_pointer_cast<Fursecuri>(icomanda.first);
            if (tort) {
                caloriiTotal+=tort->calculeazaCaloriiTotal()*icomanda.second;
            } else if (prajituraVegana) {
                caloriiTotal+=prajituraVegana->calculeazaCaloriiTotal()*icomanda.second;
            } else if (fursecuri) {
                caloriiTotal+=fursecuri->calculeazaCaloriiTotal()*icomanda.second;
            }
        }
    } else {
        std::cout<<"Comanda cu ID-ul "<<id<<" nu exista!"<<std::endl;
    }
    return caloriiTotal;
}


float Candybar::calculeazaPretTotal(int id) const {
    float pretTotal = 0.0;
    std::unordered_map<int, std::vector<std::pair<std::shared_ptr<Prajitura>, int>>>::const_iterator i=comanda.find(id);
    if (i != comanda.end()) {
        for (const auto& icomanda : i->second) {
            std::shared_ptr<Tort> tort=std::dynamic_pointer_cast<Tort>(icomanda.first);
            std::shared_ptr<PrajituraVegana> prajituraVegana=std::dynamic_pointer_cast<PrajituraVegana>(icomanda.first);
            std::shared_ptr<Fursecuri> fursecuri=std::dynamic_pointer_cast<Fursecuri>(icomanda.first);
            if (tort) {
                pretTotal+=tort->calculeazaPretTotal()*icomanda.second;
            } else if (prajituraVegana) {
                pretTotal+=prajituraVegana->calculeazaPretTotal()*icomanda.second;
            } else if (fursecuri) {
                pretTotal+=fursecuri->calculeazaPretTotal()*icomanda.second;
            }
        }
    } else {
        std::cout<<"Comanda cu ID-ul "<<id<<" nu exista!"<<std::endl;
    }
    return pretTotal;
}

void Candybar::afiseazaDetalii(int id) const {
    std::unordered_map<int, std::vector<std::pair<std::shared_ptr<Prajitura>, int>>>::const_iterator i = comanda.find(id);
    if (i!=comanda.end()) {
        std::cout<<"~~~DETALII COMANDA~~~"<<std::endl;
        std::cout<<"Produsele comandate sunt:"<<std::endl;
        for (const auto& icomanda : i->second) {
            std::cout<<icomanda.first->getNume()<<" - Cantitate: "<<icomanda.second<<" bucati"<<std::endl;
        }
        std::cout<<"Pretul total pentru comanda este: "<<calculeazaPretTotal(id)<<" RONI"<<std::endl;
    } else {
        std::cout<<"Comanda cu ID-ul "<<id<<" nu exista!"<<std::endl;

    }
}
