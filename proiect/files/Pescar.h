//clasa pentru partenerul userului din barca

#ifndef PESCAR_H
#define PESCAR_H

#include "User.h"
#include <vector>
#include <string>

class Pescar : public User {
    std::vector<std::string> m_replici; 
public:
    Pescar();
    Pescar(std::string nume, int varsta);
    Pescar(const Pescar& p);
    ~Pescar();

    void DaReplica() const;
    void AfisareDetalii() const override;
    void IncarcaRepliciDinFisier(const std::string& numeFisier = "date/replici.txt");
};

#endif
