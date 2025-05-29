#include "undita.h"
//clasa pentru undite primite de la pescar, fiecare cu numar limitat de utilizari


Undita::Undita(std::string nume, int utilizari) {
    m_info.nume = nume;
    m_info.utilizari_ramase = utilizari;
}

void Undita::Foloseste() {
    if (m_info.utilizari_ramase > 0)
        m_info.utilizari_ramase--;
}

bool Undita::Epuizata() const {
    return m_info.utilizari_ramase <= 0;
}

std::string Undita::GetNume() const {
    return m_info.nume;
}

int Undita::GetUtilizariRamase() const {
    return m_info.utilizari_ramase;
}

void Undita::Afiseaza() const {
    std::cout << "Undita: " << m_info.nume << " (" << m_info.utilizari_ramase << " utilizari ramase)\n";
}
