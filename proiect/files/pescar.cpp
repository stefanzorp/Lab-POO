#include "pescar.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

//pescarul foloseste replicile din date/replici.txt, alege una random de fiecare data cand e apelat de jucator

Pescar::Pescar() : User("Pescarul Vasile", 50) {
    IncarcaRepliciDinFisier();
}

Pescar::Pescar(std::string nume, int varsta) : User(nume, varsta) {
    IncarcaRepliciDinFisier();
}

Pescar::Pescar(const Pescar& p) : User(p), m_replici(p.m_replici) {}

Pescar::~Pescar() {}

//citeste din fisier replici posibile
void Pescar::IncarcaRepliciDinFisier(const std::string& numeFisier) {
    std::ifstream in(numeFisier);
    if (!in) {
        std::cerr << "Eroare: nu pot deschide fisierul de replici.\n";
        return;
    }

    m_replici.clear();
    std::string linie;
    while (std::getline(in, linie)) {
        if (!linie.empty())
            m_replici.push_back(linie);
    }

    in.close();
}

//prin asta se alege replica pe care o spune
void Pescar::DaReplica() const {
    if (m_replici.empty()) {
        std::cout << "Pescarul e mut azi...\n";
        return;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int index = std::rand() % m_replici.size();
    std::cout << "Pescarul zice: \"" << m_replici[index] << "\"\n";
}

void Pescar::AfisareDetalii() const {
    std::cout << "Pescar: " << GetNume() << ", Varsta: " << GetVarsta() << " ani\n";
}

//counter pentru ca la 10 replici, jucatorul primeste o undita bonus
void Pescar::InregistreazaIntrebare() {
    m_intrebari_primite++;
}

Undita* Pescar::OferaUndita() {
    if (m_intrebari_primite >= 10) {
        m_intrebari_primite = 0; // reset
        std::cout << "Pescarul: Ti-am vazut interesul, ia o undita cadou!\n";
        return new Undita("Undita veche dar norocoasa", 3 + rand() % 4);
    }
    return nullptr;
}