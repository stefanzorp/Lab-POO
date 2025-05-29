#include "Acvariu.h"
#include <iostream>
#include <vector>
#include <fstream>

Acvariu::Acvariu():User(), m_id_acvariu(0), m_istoric_pesti(std::vector<int>()) {}; //Constructor implicit

Acvariu::Acvariu(std::string nume, int varsta, int id_acvariu, std::vector<int> istoric_pesti):
User(nume, varsta), m_id_acvariu(id_acvariu), m_istoric_pesti(istoric_pesti) {}; //Constructor parametrizat

Acvariu::Acvariu(const Acvariu& a): User(a), m_id_acvariu(a.m_id_acvariu), m_istoric_pesti(a.m_istoric_pesti) {}; //Copy constructor

Acvariu::~Acvariu() {}; //Destructor

//Getteri si setteri
int Acvariu::GetIdA() const { return m_id_acvariu; };
std::vector<int> Acvariu::GetIstoric() const { return m_istoric_pesti; };

void Acvariu::SetIdA(int id_acvariu) { m_id_acvariu=id_acvariu; };


//Supraincarcarea operatorului += 
Acvariu& Acvariu::operator+=(int peste)
{
    m_istoric_pesti.push_back(peste);
    return *this;
};

//Metode suplimentare
void Acvariu::AdaugaPeste(int peste)
{
    m_istoric_pesti.insert(m_istoric_pesti.begin()+m_istoric_pesti.size(),peste);
};

void Acvariu::AfisareIstoricPesti()
{
    for(auto& peste : m_istoric_pesti)
        std::cout<<peste<<" ";
};

void Acvariu::AfisareDetalii() const //Metoda suprascrisa 
{
    std::cout<<"Nume: "<<GetNume()<<std::endl;
    std::cout<<"Varsta: "<<GetVarsta()<<std::endl;
    std::cout<<"ID Acvariu: "<<GetIdA()<<"\n";
    std::cout<<"\n"; 
}