#include "Pescar.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Pescar::Pescar() : User("Pescarul Vasile", 50) {
    IncarcaRepliciDinFisier();
}

Pescar::Pescar(std::string nume, int varsta) : User(nume, varsta) {
    IncarcaRepliciDinFisier();
}

Pescar::Pescar(const Pescar& p) : User(p), m_replici(p.m_replici) {}

Pescar::~Pescar() {}

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
