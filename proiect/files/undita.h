#ifndef UNDITA_H
#define UNDITA_H

#include <string>
#include <iostream>

//sturct pt detalii despre undita
struct UnditaInfo {
    std::string nume;
    int utilizari_ramase;
};

class Undita {
private:
    UnditaInfo m_info;

public:
    Undita(std::string nume = "Undita simpla", int utilizari = 5);

    void Foloseste(); // scade utilizari
    bool Epuizata() const;

    std::string GetNume() const;
    int GetUtilizariRamase() const;

    void Afiseaza() const;
};

#endif
