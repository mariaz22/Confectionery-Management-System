/*#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

// Definim tipul de client
enum class TipClient { VIP, Normal };

// Clasa template Client
template <class T>
class Client {
private:
    std::string nume;
    std::string prenume;
    std::string dataNasterii;
    TipClient tip;
    std::vector<T> preferinte;
    std::vector<float> sumeCheltuite;
    std::vector<std::string> intolerante;

public:
    Client(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, TipClient tip,
           const std::vector<T>& preferinte, const std::vector<float>& sumeCheltuite, const std::vector<std::string>& intolerante);

    void afiseazaClientiAlergiciLa(const std::string& aliment) const;
    void afiseazaDetaliiClient() const;
    float calculeazaSumaMedieCheltuita() const;

    void afiseazaPreferinte() const;

    // Funcția template adăugată
    template <typename U, typename V>
    float calculeazaRaport(U val1, V val2) const;
};

// Implementarea funcțiilor template în fișierul de antet

template <class T>
Client<T>::Client(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, TipClient tip,
                  const std::vector<T>& preferinte, const std::vector<float>& sumeCheltuite, const std::vector<std::string>& intolerante)
    : nume(nume), prenume(prenume), dataNasterii(dataNasterii), tip(tip), preferinte(preferinte), sumeCheltuite(sumeCheltuite), intolerante(intolerante) {}

template <class T>
void Client<T>::afiseazaClientiAlergiciLa(const std::string& aliment) const {
    if (std::find(intolerante.begin(), intolerante.end(), aliment) != intolerante.end()) {
        std::cout << nume << " " << prenume << " este alergic la " << aliment << "." << std::endl;
    }
}

template <class T>
void Client<T>::afiseazaDetaliiClient() const {
    std::cout << "Client: " << nume << " " << prenume << std::endl;
    std::cout << "Data Nasterii: " << dataNasterii << std::endl;
    std::cout << "Tip Client: " << (tip == TipClient::VIP ? "VIP" : "Normal") << std::endl;
    std::cout << "Preferinte: ";
    for (const auto& pref : preferinte) {
        std::cout << pref << " ";
    }
    std::cout << std::endl;
    std::cout << "Intolerante: ";
    for (const auto& intoleranta : intolerante) {
        std::cout << intoleranta << " ";
    }
    std::cout << std::endl;
    std::cout << "Sume Cheltuite: ";
    for (const auto& suma : sumeCheltuite) {
        std::cout << suma << " ";
    }
    std::cout << std::endl;
}

template <class T>
float Client<T>::calculeazaSumaMedieCheltuita() const {
    if (sumeCheltuite.empty()) {
        return 0.0f;
    }
    float total = std::accumulate(sumeCheltuite.begin(), sumeCheltuite.end(), 0.0f);
    return total / sumeCheltuite.size();
}

template <class T>
void Client<T>::afiseazaPreferinte() const {
    std::cout << "Preferinte: ";
    for (const auto& pref : preferinte) {
        std::cout << pref << " ";
    }
    std::cout << std::endl;
}

// Implementarea funcției template calculeazaRaport
template <class T>
template <typename U, typename V>
float Client<T>::calculeazaRaport(U val1, V val2) const {
    if (val2 == 0) {
        throw std::invalid_argument("Valoarea divisorului nu poate fi zero.");
    }
    return static_cast<float>(val1) / static_cast<float>(val2);
}

*/
