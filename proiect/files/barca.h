#ifndef BARCA_H
#define BARCA_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Acvariu.h"
#include "Mancare.h"
#include "Pescar.h"
#include "Peste.h"
#include "User.h"
#include "Undita.h"


class Barca
{
    Pescar m_pescar;
    std::vector<Undita> m_undite; 
    std::vector <Peste> m_pesti; 
    std::vector <Peste> m_prinsi;
    std::vector <Acvariu> m_acvariu;
    std::vector <Mancare> m_rucsac;
public:
    Barca();
    ~Barca();
    void Ruleaza();

    void MeniuBarca();


    void RealizeazaPescuit();
    void VizualizareAcvariu();
    void VizualizareJurnal();
    void VizualizareRucsac();

    void IncarcaPestiiDinFisier();
    void IncarcaPrinsiDinFisier();
    void ReseteazaAcvariu();
    void IntreabaPescarul();

};

#endif 