#include "Fabrica.h"

Fabrica::Fabrica(User *ut)
{
    Ut_Atual = ut;
    LUsers.push_back(ut);
}

Fabrica::~Fabrica()
{
    //dtor
}
bool Fabrica::Load(const string &ficheiro)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return true;
}
bool Fabrica::Add(User *ut)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return true;
}

