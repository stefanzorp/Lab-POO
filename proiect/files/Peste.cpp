#include "Peste.h"
#include <iostream>

// Constructori
Peste::Peste() 
    : m_nume("nu avem"), m_familie("nu avem"), m_zona("nu avem"), m_masa(0), m_id_peste(0) {}

Peste::Peste(std::string nume, std::string familie, std::string zona, int masa, int id_peste)
    : m_nume(nume), m_familie(familie), m_zona(zona), m_masa(masa), m_id_peste(id_peste) {}

Peste::Peste(const Peste& p)
    : m_nume(p.m_nume), m_familie(p.m_familie), m_zona(p.m_zona),
      m_masa(p.m_masa), m_id_peste(p.m_id_peste) {}

Peste::~Peste() {}

// Getteri
std::string Peste::GetNume() const { return m_nume; }
std::string Peste::GetFamilie() const { return m_familie; }
std::string Peste::GetZona() const { return m_zona; }
int Peste::GetMasa() const { return m_masa; }
int Peste::GetIdPeste() const { return m_id_peste; }  // <-- implementare corectă

// Setteri
void Peste::SetNume(std::string nume) { m_nume = nume; }
void Peste::SetFamilie(std::string familie) { m_familie = familie; }
void Peste::SetZona(std::string zona) { m_zona = zona; }

void Peste::SetMasa(int masa) {
    if (masa < 0)
        std::cout << "masa nu poate fi negativa";
    else
        m_masa = masa;
}

void Peste::SetIdPeste(int id_peste) { m_id_peste = id_peste; }

// Afișare
void Peste::ArataInformatii() const {
    std::cout << "Nume peste: " << m_nume << "\n";
    std::cout << "Familie: " << m_familie << "\n";
    std::cout << "Zona: " << m_zona << "\n";
    std::cout << "Masa: " << m_masa << "\n";
    std::cout << "ID: " << m_id_peste << "\n";
}

// Supraincarcare <<
std::ostream& operator<<(std::ostream& os, const Peste& peste) {
    os << "Peste: " << peste.m_nume
       << ", Familie: " << peste.m_familie
       << ", Zona: " << peste.m_zona
       << ", Masa: " << peste.m_masa << "g"
       << ", ID: " << peste.m_id_peste;
    return os;
}
