#include "User.h"
#include <iostream>

//Constructori si destructor
User::User(): m_nume("Necunoscut"), m_varsta(0) {}; 

User::User(std::string nume, int varsta):
m_nume(nume), m_varsta(varsta) {};

User::User(const User& p): m_nume(p.m_nume), m_varsta(p.m_varsta) {};

User::~User() {} 

std::string User::GetNume() const { return m_nume; }
int User::GetVarsta() const { return m_varsta; }

void User::SetNume(std::string nume) { m_nume=nume; }
void User::SetVarsta(int varsta) 
{
    if(varsta<0)
        std::cout<<"varsta nu poate fi negativa";
    else
        m_varsta=varsta;
}
