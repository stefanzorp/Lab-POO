//clasa pentru partenerul userului din barca

#ifndef PESCAR_H
#define PESCAR_H

#include "user.h"
#include "undita.h"

#include <vector>
#include <string>
#include <fstream>

class Pescar : public User {
private:
    std::vector<std::string> m_replici;
    int m_intrebari_primite = 0;

public:
    Pescar();
    Pescar(std::string nume, int varsta);
    Pescar(const Pescar& p);
    ~Pescar();

    void IncarcaRepliciDinFisier(const std::string& fisier = "date/replici.txt");
    void DaReplica() const;
    void AfisareDetalii() const;

    Undita* OferaUndita();
    void InregistreazaIntrebare(); // ++counter
};

#endif
