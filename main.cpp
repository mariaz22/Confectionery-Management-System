/*#include <vector>
#include <memory>
#include <cmath>
#include <iostream>
#include "Tort.h"
#include "Prajitura_Vegana.h"
#include "Fursecuri.h"
#include "Candybar.h"
#include "Client.h"

void afisareMeniu() {
    std::cout<<"~~~~ MENIU ~~~~"<<std::endl;
    std::cout<<"1. Adauga produs in comanda"<<std::endl;
    std::cout<<"2. Afiseaza timpul total de preparare pentru comanda"<<std::endl;
    std::cout<<"3. Afiseaza numarul total de calorii pentru comanda"<<std::endl;
    std::cout<<"4. Afiseaza detalii comanda"<<std::endl;
    std::cout<<"5. Afiseaza stocul cofetariei"<<std::endl;
    std::cout<<"6. Sectiunea clienti"<<std::endl;
    std::cout<<"0. Iesire"<<std::endl;
}

void afisareMeniuClienti() {
    std::cout<<"~~~~ SECTIUNEA CLIENTI ~~~~"<<std::endl;
    std::cout<<"1. Alege client si afiseaza detalii"<<std::endl;
    std::cout<<"2. Afiseaza clientii intoleranti la un anumit aliment"<<std::endl;
    std::cout<<"3. Afiseaza suma medie cheltuita de un client in cofetarie"<<std::endl;
    std::cout<<"0. Inapoi"<<std::endl;
}

int main() {
    std::vector<std::shared_ptr<Prajitura>> stoc;

    stoc.push_back(std::make_shared<PrajituraVegana>("Clatite vegane", 100, 30, 60));
    stoc.push_back(std::make_shared<Tort>("Tort de aniversare", 1500, "Rotund", "Aniversare", 60, 15));
    stoc.push_back(std::make_shared<Fursecuri>("Fursecuri cu ciocolata", 50, "Patrate", 60, 5));
    stoc.push_back(std::make_shared<Tort>("Tort de nunta", 1500, "Rotund", "Nunta", 60, 15));
    stoc.push_back(std::make_shared<PrajituraVegana>("Tiramisu vegan", 100, 60, 120));
    stoc.push_back(std::make_shared<Fursecuri>("Fursecuri cu cocos", 50, "Rotunde", 120, 10));

    Candybar candyBar;

    // Vectori pentru clienti VIP și normali
    std::vector<Client<char>> clientiVIP;
    std::vector<Client<int>> clientiNormali;

    // Adăugare de exemple de clienți VIP
    clientiVIP.emplace_back("Ion", "Popescu", "1990-05-21", TipClient::VIP,
                            std::vector<char>{'A', 'B'},
                            std::vector<float>{100.0f, 150.0f},
                            std::vector<std::string>{"gluten"});
    clientiVIP.emplace_back("Maria", "Ionescu", "1988-07-12", TipClient::VIP,
                            std::vector<char>{'C', 'D'},
                            std::vector<float>{200.0f, 250.0f},
                            std::vector<std::string>{"lactoză"});
    clientiVIP.emplace_back("Vasile", "Georgescu", "1975-09-30", TipClient::VIP,
                            std::vector<char>{'E', 'F'},
                            std::vector<float>{300.0f, 350.0f},
                            std::vector<std::string>{"nuci"});

    // Adăugare de exemple de clienți normali
    clientiNormali.emplace_back("Ana", "Ionescu", "1985-03-15", TipClient::Normal,
                                std::vector<int>{1, 2},
                                std::vector<float>{50.0f, 75.0f},
                                std::vector<std::string>{"lactoză"});
    clientiNormali.emplace_back("Gheorghe", "Popa", "1992-11-22", TipClient::Normal,
                                std::vector<int>{3, 4},
                                std::vector<float>{80.0f, 90.0f},
                                std::vector<std::string>{"soia"});
    clientiNormali.emplace_back("Elena", "Marin", "1980-02-28", TipClient::Normal,
                                std::vector<int>{5, 6},
                                std::vector<float>{60.0f, 70.0f},
                                std::vector<std::string>{"arahide"});

    int optiune;
    do {
        afisareMeniu();
        std::cout<<"Introduceti optiunea: ";
        std::cin>>optiune;

        switch (optiune) {
            case 1: {
                std::cout<<"~~~ADAUGA PRODUS IN COMANDA~~~"<<std::endl;
                for (int i=0; i<stoc.size(); ++i) {
                    std::cout<<i + 1<< ". "<<stoc[i]->getNume()<<std::endl;
                }
                int index;
                std::cout<<"Introduceti indexul produsului: ";
                std::cin>>index;
                if (index>=1 && index<=stoc.size()) {
                    int cantitate, id;
                    std::cout<<"Introduceti cantitatea: ";
                    std::cin>>cantitate;
                    std::cout << "Introduceti ID-ul comenzii: ";
                    std::cin >> id;
                    if (cantitate>0) {
                        candyBar.adaugaProdus(stoc[index-1], cantitate, id);
                    } else {
                        std::cout<<"Cantitate invalida! Va rugam reintroduceti."<<std::endl;
                    }
                } else {
                    std::cout<<"Index invalid! Va rugam reintroduceti."<<std::endl;
                }
                break;
            }
            case 2: {
                std::cout<<"~~~AFISEAZA TIMPUL TOTAL DE PREPARARE PENTRU COMANDA~~~"<<std::endl;
                int id;
                std::cout<<"Introduceti ID-ul comenzii: ";
                std::cin>>id;
                std::cout<<"Timpul total de preparare pentru comanda "<<id<<" este: "<<int((candyBar.calculeazaTimpTotalPreparare(id))/60)<<" ore."<<std::endl;
                break;
            }
            case 3: {
                std::cout<<"~~~AFISEAZA NUMARUL TOTAL DE CALORII PENTRU COMANDA~~~"<<std::endl;
                int id;
                std::cout<<"Introduceti ID-ul comenzii: ";
                std::cin>>id;
                std::cout<<"Numarul total de calorii pentru comanda "<<id<<" este: "<<candyBar.calculeazaCaloriiTotal(id)<<" kcal."<<std::endl;
                break;
            }
            case 4: {
                std::cout<<"~~~AFISEAZA DETALII COMANDA~~~"<<std::endl;
                int id;
                std::cout<<"Introduceti ID-ul comenzii: ";
                std::cin>>id;
                candyBar.afiseazaDetalii(id);
                break;
            }
            case 5: {
                Prajitura::afiseazaStoc(stoc);
                break;
            }
            case 6: {
                int optiuneClienti;
                do {
                    afisareMeniuClienti();
                    std::cout<<"Introduceti optiunea: ";
                    std::cin>>optiuneClienti;

                    switch (optiuneClienti) {
                        case 1: {
                            std::cout<<"~~~Alege client si afiseaza detalii~~~"<<std::endl;
                            std::cout<<"Clienti VIP:"<<std::endl;
                            for (int i = 0; i < clientiVIP.size(); ++i) {
                                std::cout<<i + 1<< ". "<<clientiVIP[i].getNume()<<" "<<clientiVIP[i].getPrenume()<<std::endl;
                            }
                            std::cout<<"Clienti Normali:"<<std::endl;
                            for (int i = 0; i < clientiNormali.size(); ++i) {
                                std::cout<<i + 1<< ". "<<clientiNormali[i].getNume()<<" "<<clientiNormali[i].getPrenume()<<std::endl;
                            }
                            int index;
                            std::cout<<"Introduceti indexul clientului: ";
                            std::cin>>index;
                            if (index>=1 && index<=clientiVIP.size()) {
                                clientiVIP[index-1].afiseazaDetaliiClient();
                            } else if (index>clientiVIP.size() && index<=clientiVIP.size()+clientiNormali.size()) {
                                clientiNormali[index-1-clientiVIP.size()].afiseazaDetaliiClient();
                            } else {
                                std::cout<<"Index invalid! Va rugam reintroduceti."<<std::endl;
                            }
                            break;
                        }
                        case 2: {
                            std::cout<<"~~~Afiseaza clientii intoleranti la un anumit aliment~~~"<<std::endl;
                            std::string aliment;
                            std::cout<<"Introduceti alimentul: ";
                            std::cin>>aliment;
                            std::cout<<"Clienti VIP alergici la "<<aliment<<":"<<std::endl;
                            for (const auto& client : clientiVIP) {
                                client.afiseazaClientiAlergiciLa(aliment);
                            }
                            std::cout<<"Clienti Normali alergici la "<<aliment<<":"<<std::endl;
                            for (const auto& client : clientiNormali) {
                                client.afiseazaClientiAlergiciLa(aliment);
                            }
                            break;
                        }
                        case 3: {
                            std::cout<<"~~~Afiseaza suma medie cheltuita de un client in cofetarie~~~"<<std::endl;
                            std::cout<<"Clienti VIP:"<<std::endl;
                            for (int i = 0; i < clientiVIP.size(); ++i) {
                                std::cout<<i + 1<< ". "<<clientiVIP[i].getNume()<<" "<<clientiVIP[i].getPrenume()<<std::endl;
                            }
                            std::cout<<"Clienti Normali:"<<std::endl;
                            for (int i = 0; i < clientiNormali.size(); ++i) {
                                std::cout<<i + 1<< ". "<<clientiNormali[i].getNume()<<" "<<clientiNormali[i].getPrenume()<<std::endl;
                            }
                            int index;
                            std::cout<<"Introduceti indexul clientului: ";
                            std::cin>>index;
                            if (index>=1 && index<=clientiVIP.size()) {
                                std::cout<<"Suma medie cheltuita de clientul "<<clientiVIP[index-1].getNume()<<" "<<clientiVIP[index-1].getPrenume()<<" este: "<<clientiVIP[index-1].calculeazaSumaMedieCheltuita()<<" unitati monetare."<<std::endl;
                            } else if (index>clientiVIP.size() && index<=clientiVIP.size()+clientiNormali.size()) {
                                std::cout<<"Suma medie cheltuita de clientul "<<clientiNormali[index-1-clientiVIP.size()].getNume()<<" "<<clientiNormali[index-1-clientiVIP.size()].getPrenume()<<" este: "<<clientiNormali[index-1-clientiVIP.size()].calculeazaSumaMedieCheltuita()<<" unitati monetare."<<std::endl;
                            } else {
                                std::cout<<"Index invalid! Va rugam reintroduceti."<<std::endl;
                            }
                            break;
                        }
                        case 0: {
                            std::cout<<"Inapoi la meniul principal"<<std::endl;
                            break;
                        }
                        default: {
                            std::cout<<"Optiune invalida! Va rugam sa reintroduceti."<<std::endl;
                            break;
                        }
                    }
                } while (optiuneClienti != 0);
                break;
            }
            case 0: {
                std::cout<<"La revedere!"<<std::endl;
                break;
            }
            default: {
                std::cout<<"Optiune invalida! Va rugam sa reintroduceti."<<std::endl;
                break;
            }
        }
    } while (optiune!=0);

    return 0;
}
*/
#include <vector>
#include <memory>
#include <cmath>
#include <iostream>
#include "Tort.h"
#include "Prajitura_Vegana.h"
#include "Fursecuri.h"
#include "Candybar.h"

void afisareMeniu() {
    std::cout<<"~~~~ MENIU ~~~~"<<std::endl;
    std::cout<<"1. Adauga produs in comanda"<<std::endl;
    std::cout<<"2. Afiseaza timpul total de preparare pentru comanda"<<std::endl;
    std::cout<<"3. Afiseaza numarul total de calorii pentru comanda"<<std::endl;
    std::cout<<"4. Afiseaza detalii comanda"<<std::endl;
    std::cout<<"5. Afiseaza stocul cofetariei"<<std::endl;
    std::cout<<"0. Iesire"<<std::endl;
}

int main() {
    std::vector<std::shared_ptr<Prajitura>> stoc;


    stoc.push_back(std::make_shared<PrajituraVegana>("Clatite vegane", 100, 30, 60));
    stoc.push_back(std::make_shared<Tort>("Tort de aniversare", 1500, "Rotund", "Aniversare", 60, 15));
    stoc.push_back(std::make_shared<Fursecuri>("Fursecuri cu ciocolata", 50, "Patrate", 60, 5));
    stoc.push_back(std::make_shared<Tort>("Tort de nunta", 1500, "Rotund", "Nunta", 60, 15));
    stoc.push_back(std::make_shared<PrajituraVegana>("Tiramisu vegan", 100, 60, 120));
    stoc.push_back(std::make_shared<Fursecuri>("Fursecuri cu cocos", 50, "Rotunde", 120, 10));

    Candybar candyBar;

    int optiune;
    do {
        afisareMeniu();
        std::cout<<"Introduceti optiunea: ";
        std::cin>>optiune;

        switch (optiune) {
            case 1: {
                std::cout<<"~~~ADAUGA PRODUS IN COMANDA~~~"<<std::endl;
                for (int i=0; i<stoc.size(); ++i) {
                    std::cout<<i + 1<< ". "<<stoc[i]->getNume()<<std::endl;
                }
                int index;
                std::cout<<"Introduceti indexul produsului: ";
                std::cin>>index;
                if (index>=1 && index<=stoc.size()) {
                    int cantitate, id;
                    std::cout<<"Introduceti cantitatea: ";
                    std::cin>>cantitate;
                    std::cout << "Introduceti ID-ul comenzii: ";
                    std::cin >> id;
                    if (cantitate>0) {
                        candyBar.adaugaProdus(stoc[index-1], cantitate, id);
                    } else {
                        std::cout<<"Cantitate invalida! Va rugam reintroduceti."<<std::endl;
                    }
                } else {
                    std::cout<<"Index invalid! Va rugam reintroduceti."<<std::endl;
                }
                break;
            }
            case 2: {
                std::cout<<"~~~AFISEAZA TIMPUL TOTAL DE PREPARARE PENTRU COMANDA~~~"<<std::endl;
                int id;
                std::cout<<"Introduceti ID-ul comenzii: ";
                std::cin>>id;
                std::cout<<"Timpul total de preparare pentru comanda "<<id<<" este: "<<int((candyBar.calculeazaTimpTotalPreparare(id))/60)<<" ore."<<std::endl;
                break;
            }
            case 3: {
                std::cout<<"~~~AFISEAZA NUMARUL TOTAL DE CALORII PENTRU COMANDA~~~"<<std::endl;
                int id;
                std::cout<<"Introduceti ID-ul comenzii: ";
                std::cin>>id;
                std::cout<<"Numarul total de calorii pentru comanda "<<id<<" este: "<<candyBar.calculeazaCaloriiTotal(id)<<" kcal."<<std::endl;
                break;
            }
            case 4: {
                std::cout<<"~~~AFISEAZA DETALII COMANDA~~~"<<std::endl;
                int id;
                std::cout<<"Introduceti ID-ul comenzii: ";
                std::cin>>id;
                candyBar.afiseazaDetalii(id);
                break;
            }
            case 5: {
                Prajitura::afiseazaStoc(stoc);
                break;
            }
            case 0: {
                std::cout<<"La revedere!"<<std::endl;
                break;
            }
            default: {
                std::cout<<"Optiune invalida! Va rugam sa reintroduceti."<<std::endl;
                break;
            }
        }
    } while (optiune!=0);

    return 0;
}

