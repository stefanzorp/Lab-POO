#ifndef BARCA_H
#define BARCA_H

#include <iostream>
#include <vector>

#include "Acvariu.h"
#include "Mancare.h"
#include "Pescar.h"
#include "Peste.h"
#include "User.h"

class Barca
{
    std::vector <Peste> m_pesti;
    std::vector <Peste> m_prinsi;
    std::vector <Acvariu> m_acvariu;
public:
    Barca();
    ~Barca();
    void Ruleaza();

    void MeniuBarca();


    void RealizeazaPescuit();
    void VizualizareAcvariu();
    void VizualizareJurnal();

    void IncarcaPestiiDinFisier();
    void IncarcaPrinsiDinFisier();
};

#endif 