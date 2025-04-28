#include "Barca.h"
#include "Peste.h"
#include <iostream>
#include <fstream>

//iau din fisiere pt vectori
Barca::Barca() {
    IncarcaPestiiDinFisier();
    IncarcaPrinsiDinFisier();
}; 

Barca::~Barca() {};

void Barca::Ruleaza() //apelez in main sa mearga totu
{
    int opt;

    do {
        std::cout << "Esti pe barca, alege actiunea:\n";
        std::cout << "1> Pescuieste\n";
        std::cout << "2> Vezi acvariul\n";
        std::cout << "3> Vezi jurnal\n";
        std::cout << "4> Sari din barca\n";
        std::cout << "Deci?: ";
        std::cin >> opt;

        switch (opt) {
            case 1:
                RealizeazaPescuit();
                break;
            case 2:
                VizualizareAcvariu();
                break;
            case 3:
                VizualizareJurnal();
                break;
            case 4:
                std::cout << "Bye bye sper ca stii sa inoti.\n";
                break;
            default:
                std::cout << "ai doar optiunile 1 2 3 4, nu stiu mai multe\n";
                break;
        }

    } while (opt != 4);
}

//afisare toti pestii posibili
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (eroare cu supraincarcarea trb sa rezolv)
void Barca::VizualizareJurnal()
{  
    std::cout<<"In jurnal pestii sunt:\n";
    for(auto& peste : m_pesti) //referinta
    {
        std::cout << peste <<"\n"; //supraincarcarea <<
    }
}

//afisarea pestilor prinsi
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (eroare cu supraincarcarea trb sa rezolv)
void Barca::VizualizareAcvariu()
{  
    std::cout<<"In acvariu ai prins:\n";
    for(auto& prins : m_prinsi) //referinta - pentru a nu copia fiecare element din vector - este accesat obiectul in sine
    {
        std::cout<< prins <<"\n";
    std::cout<<"\n";
    }
}

//pt bagarea in vector a toti pestii
void Barca::IncarcaPestiiDinFisier()
{
    std::ifstream in("date/pesti.txt");

    if(!in)
    {
        std::cerr<<"Eroare\n"; 
        return;
    }

    int id_peste,masa;
    std::string nume;
    std::string familie;
    std::string zona;

    while(in >> id_peste >> nume >> familie >> zona >> masa)
    {
        Peste peste;
        peste.SetNume(nume);
        peste.SetFamilie(familie);
        peste.SetZona(zona);
        peste.SetMasa(masa);
        peste.SetIdPeste(id_peste);

        m_pesti.push_back(peste); //bag in vector pestele

    }
    in.close();
}

//pt citirea pestilor prinsi deja in fisier
void Barca::IncarcaPrinsiDinFisier()
{
    std::ifstream in("date/prinsi.txt");

    if(!in)
    {
        std::cerr<<"Eroare\n"; 
        return;
    }

    int id_peste,masa;
    std::string nume;
    std::string familie;
    std::string zona;

    while(in >> id_peste >> nume >> familie >> zona >> masa)
    {
        Peste peste;
        peste.SetNume(nume);
        peste.SetFamilie(familie);
        peste.SetZona(zona);
        peste.SetMasa(masa);
        peste.SetIdPeste(id_peste);

        m_prinsi.push_back(peste); //bag in vector pestele

    }
    in.close();
}


//mai trb sa fac functiile pentru adaugarea in fisierul de pesti prinsi