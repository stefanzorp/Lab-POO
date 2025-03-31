#ifndef PESTE_H
#define PESTE_H

#include <iostream>
using namespace std;

class Peste
{
    string nume;
    string familie;
    string zona;
    int masa;
public:
    Peste(): nume("nu avem"), familie("nu avem"), zona("nu avem"), masa(0) {}; //constructor initializare, apare pestele da n are nimic

    Peste( string familie, string zona, int masa): //constructor initializeaza atributele cu arg primite, pestele are ceva acum
    familie(familie), zona(zona), masa(masa) {};  

    Peste(const Peste& p): nume(p.nume), familie(p.familie), zona(p.zona), masa(p.masa) {}; //constructor care copiaza 

    ~Peste() {}; //deconstructor bye bye
    //Suprascrierea operatorului de atribuire
    Peste& operator=(const Peste& p);

    string getNume();
    string getFamilie();
    string getZona();
    int getMasa();

    void setNume(string nume);
    void setFamilie(string familie);
    void setZona(string zona);
    void setMasa(int masa);

};

#endif