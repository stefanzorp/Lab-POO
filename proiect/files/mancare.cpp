#include "mancare.h"

#include <iostream>

// Constructori
Mancare::Mancare() 
    : m_nume("necunoscut"), m_id_mancare(0) {}

Mancare::Mancare(std::string nume, int id_mancare)
    : m_nume(nume), m_id_mancare(id_mancare) {}

Mancare::Mancare(const Mancare& m)
    : m_nume(m.m_nume), m_id_mancare(m.m_id_mancare) {}

Mancare::~Mancare() {}

// Getteri
int Mancare::GetIdMancare() const { return m_id_mancare; }
std::string Mancare::GetNume() const { return m_nume; }

// Setteri
void Mancare::SetIdMancare(int id_mancare) { m_id_mancare = id_mancare; }
void Mancare::SetNume(std::string nume) { m_nume = nume; }

// Afișare
void Mancare::ArataInformatii() const {
    std::cout << "Mancare: " << m_nume << "\n";
    std::cout << "ID: " << m_id_mancare << "\n";
}

// Supraincarcare <<
std::ostream& operator<<(std::ostream& os, const Mancare& m) {
    os << "Mancare: " << m.m_nume << ", ID: " << m.m_id_mancare;
    return os;
}

void Mancare::Afiseaza() const {
    std::cout << *this << "\n";
}
