#ifndef PESTE_H
#define PESTE_H

#include <iostream>

class Peste
{
    std::string m_nume;
    std::string m_familie;
    std::string m_zona;
    int m_masa;
    int m_id_peste;
public:
    Peste();
    Peste(std::string nume, std::string familie, std::string zona, int masa, int id_peste); //constructor initializeaza atributele cu arg primite, pestele are ceva acum
    Peste(const Peste& p);

    virtual ~Peste();

    //Suprascrierea operatorului de atribuire
    Peste& operator=(const Peste& p);

    std::string GetNume() const;
    std::string GetFamilie() const;
    std::string GetZona() const;
    int GetMasa() const;
    int GetIdPeste() const;


    void SetNume(std::string nume);
    void SetFamilie(std::string familie);
    void SetZona(std::string zona);
    void SetMasa(int masa);
    void SetIdPeste(int id_peste);

    virtual void ArataInformatii() const;
    friend std::ostream& operator<<(std::ostream& os, const Peste& peste);

};

#endif