#include "Prajitura.h"
#include <iostream>

Prajitura::Prajitura(const std::string& nume, float gramaj) : nume(nume), gramaj(gramaj) {}

const std::string& Prajitura::getNume() const {
    return nume;
}

float Prajitura::getGramaj() const {
    return gramaj;
}


void Prajitura::afiseazaStoc(const std::vector<std::shared_ptr<Prajitura>>& stoc) {  //*
    std::cout<<"Stocul este:"<<std::endl;
    for (const auto& prajitura : stoc) {
        std::cout<<"Nume: "<<prajitura->getNume()<<", Cantitate: "<<prajitura->getGramaj()<<" grame"<<std::endl;
    }
}
