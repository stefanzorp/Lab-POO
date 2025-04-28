#ifndef USER_H
#define USER_H

#include <iostream>

class User
{
    std::string m_nume;
    int m_varsta;
public:
    User(); 
    User(std::string nume, int varsta); 
    User(const User& p);

    virtual ~User();  

    std::string GetNume() const;
    int GetVarsta() const;

    void SetNume(std::string nume);
    void SetVarsta(int varsta);

    virtual void AfisareDetalii() const = 0; 
};


#endif