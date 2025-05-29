#include "Barca.h"
#include "Peste.h"
#include <iostream>
#include <cstdlib> // pentru rand, srand
#include <ctime>   // pentru time
#include <fstream>
#include <random>

//iau din fisiere datele pt vectori
Barca::Barca() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // init random o singură dată (aveam niste probleme cu el cand il apelam mai jos si l-am mutat aici)
    IncarcaPestiiDinFisier();
    IncarcaPrinsiDinFisier();
}


Barca::~Barca() {};

void Barca::Ruleaza() //apelez in main sa mearga totu
{
    int opt;

    do {
        std::cout << "  _      _       _        _         _ \n";
        std::cout << "><_>---><_>----><_>-----><_>------><_>\n";
        std::cout << "Esti pe barca, alege actiunea:\n";
        std::cout << "-X----------------------------------X-\n";
        std::cout << "1> Pescuieste | 2> Vezi acvariul | 3> Vezi jurnal | 4> Varsa pestii din acvariu \n";
        std::cout << "5> Intreaba pe domnul pescar | 6> Deschide rucsacul | 7> Sari din barca \n"; 
        std::cout << "-X----------------------------------X-\n";
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
                ReseteazaAcvariu();
                break;
            case 5:
                IntreabaPescarul();
                break;
            case 6:
                VizualizareRucsac();
                break;
            case 7:
                std::cout << "Bye bye sper ca stii sa inoti.\n";
                break;
            default:
                std::cout << "ai doar optiunile 1-7, nu stiu mai multe\n";
                break;
        }

    } while (opt != 7);
}

void Barca::IntreabaPescarul() {
    m_pescar.DaReplica();
    m_pescar.InregistreazaIntrebare();

    Undita* unditaNoua = m_pescar.OferaUndita();
    if (unditaNoua) {
        m_undite.push_back(*unditaNoua);
        delete unditaNoua;
    }
}

void Barca::VizualizareRucsac() {
    std::cout << "-X------------- R U C S A C -------------X-\n";

    if (m_rucsac.empty() && m_undite.empty()) {
        std::cout << "Rucsacul e gol... n-ai prins nici de mancare, nici de unealta.\n";
    } else {
        if (!m_rucsac.empty()) {
            std::cout << "Mancaruri gasite:\n";
            for (const auto& m : m_rucsac)
                std::cout << m << "\n";
        }

        if (!m_undite.empty()) {
            std::cout << "\nUndite colectate:\n";
            for (const auto& u : m_undite)
                u.Afiseaza();  // afișare directă
        }
    }

    std::cout << "-X----------------------------------------X-\n";
}


//afisare toti pestii posibili
void Barca::VizualizareJurnal()
{  
    std::cout << "-X------------- J U R N A L -------------X-\n";
    std::cout<<"In jurnal pestii sunt:\n";
    for(auto& peste : m_pesti) //referinta
    {
        std::cout << peste <<"\n"; //supraincarcarea <<
    }
    std::cout << "-X----------------------------------------X-\n";
}

//afisarea pestilor prinsi
void Barca::VizualizareAcvariu()
{  
    std::cout << "-X------------ A C V A R I U ------------X-\n";
    std::cout << "In acvariu ai prins:\n";
    for(auto& prins : m_prinsi) //referinta - pentru a nu copia fiecare element din vector - este accesat obiectul in sine
    {
        std::cout<< prins <<"\n";
    std::cout<<"\n";
    }
    std::cout << "-X---------------------------------------X-\n";
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

    std::vector<Mancare> meniu = {
        { "meniu socului", 1 }, { "ciolan afumat", 2 }, { "curry", 3 }, { "clatite", 4 },
        { "shaorma", 5 }, { "tort", 6 }, { "pizza", 7 }, { "cartofi prajiti", 8 },
        { "sarmale", 9 }, { "tocanita", 10 }, { "frigarui", 11 }, { "cozonac", 12 },
        { "burger", 13 }, { "taco", 14 }, { "prajoale", 15 }
    };

    int alegere = rand() % 2;  // 0 = peste, 1 = mancare

    if (alegere == 0) {
        int index = rand() % m_pesti.size();
        Peste peste_prins = m_pesti[index];

        std::cout << "-X----------------------------------X-\n";
        std::cout << "Ai prins un miscator acvatic!\n";
        std::cout << peste_prins << "\n";
        std::cout << "-X----------------------------------X-\n";

        m_prinsi.push_back(peste_prins);

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
    } else {
        int index = rand() % meniu.size();
        Mancare m = meniu[index];

        std::cout << "-X----------------------------------X-\n";
        std::cout << "Ai pescuit... ceva delicios!\n";
        std::cout << m << "\n";
        std::cout << "-X----------------------------------X-\n";

        m_rucsac.push_back(m);
    }
}


void Barca::ReseteazaAcvariu() {
    std::ofstream out("date/acvariu.txt", std::ios::trunc); // deschidere cu trunchiere
    if (out.is_open()) {
        std::cout << "-X----------------( :( )----------------X-\n";
        std::cout << "Bye bye pestisorilor.\n";
        std::cout << "-X----------------------------------X-\n";
        out.close();
        m_prinsi.clear(); // curățăm și vectorul din memorie
    } else {
        std::cerr << "Eroare la resetarea acvariului.\n";
    }
}
