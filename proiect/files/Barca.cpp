#include "Barca.h"
#include "Peste.h"
#include <iostream>
#include <cstdlib> // pentru rand, srand
#include <ctime>   // pentru time
#include <fstream>

//iau din fisiere datele pt vectori
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
void Barca::VizualizareJurnal()
{  
    std::cout<<"In jurnal pestii sunt:\n";
    for(auto& peste : m_pesti) //referinta
    {
        std::cout << peste <<"\n"; //supraincarcarea <<
    }
}

//afisarea pestilor prinsi
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
    std::ifstream in("date/acvariu.txt");

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


void Barca::RealizeazaPescuit() {
    if (m_pesti.empty()) {
        std::cout << "Nu sunt pesti disponibili pentru pescuit.\n";
        return;
    }

    // Seed random (poți pune asta și în constructorul clasei Barca dacă vrei o singură dată)
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Alege un peste random din vector
    int index = std::rand() % m_pesti.size();
    Peste peste_prins = m_pesti[index];

    std::cout << "Ai prins un peste!\n";
    std::cout << peste_prins << "\n";

    // Adaugă în vectorul de pesti prinsi
    m_prinsi.push_back(peste_prins);

    // Scrie în fisierul acvariu.txt
    std::ofstream out("date/acvariu.txt", std::ios::app);
    if (out.is_open()) {
        out << peste_prins.GetIdPeste() << " "
            << peste_prins.GetNume() << " "
            << peste_prins.GetFamilie() << " "
            << peste_prins.GetZona() << " "
            << peste_prins.GetMasa() << "\n";
        out.close();
    } else {
        std::cerr << "Eroare: nu pot scrie in fisierul acvariu.txt.\n";
    }
}