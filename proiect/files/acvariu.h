#ifndef Acvariu_H
#define Acvariu_H

#include <iostream>
#include <vector>
#include <fstream>
#include "User.h"

class Acvariu: public User
{
    int m_id_acvariu;
    std::vector<int> m_istoric_pesti;
public:
    Acvariu(); 
    Acvariu(std::string nume, int varsta, int id_acvariu, std::vector<int> istoric_pesti); 
    Acvariu(const Acvariu& c); 

    ~Acvariu();

    int GetIdA() const;
    std::vector<int> GetIstoric() const;

    void SetIdA(int id_acvariu);

    //Supraincarcarea operatorului =+
    Acvariu& operator+=(int peste);

    void AdaugaPeste(int peste);
    void AfisareIstoricPesti();
    void AfisareDetalii() const override;
};

#endif 