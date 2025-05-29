#ifndef MANCARE_H
#define MANCARE_H

#include "iafisabil.h"

#include <string>
#include <iostream>

class Mancare : public IAfisabil{
private:
    int m_id_mancare;
    std::string m_nume;

public:
    // Constructori
    Mancare();
    Mancare(std::string nume, int id_mancare);
    Mancare(const Mancare& m);
    ~Mancare();

    // Getteri
    int GetIdMancare() const;
    std::string GetNume() const;

    // Setteri
    void SetIdMancare(int id_mancare);
    void SetNume(std::string nume);

    // Afișare
    void ArataInformatii() const;

    // Supraincarcare <<
    friend std::ostream& operator<<(std::ostream& os, const Mancare& m);
    
    void Afiseaza() const override;

};

#endif
