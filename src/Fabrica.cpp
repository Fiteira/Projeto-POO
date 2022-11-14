#include "Fabrica.h"

Fabrica::Fabrica(User *ut)
{
    Ut_Atual = ut;
    LUsers.push_back(ut);
}

Fabrica::~Fabrica()
{

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

bool Fabrica::Add(Motor *M)
{
    if (Ut_Atual)
    {
        if (Ut_Atual->PossoADD())
            LMotores.push_back(M);
        else
            cout << "Nao tens autorizacao!!!" << endl;
    }
    else
        cout << "Nao existe User!" << endl;
}

bool Fabrica::Run()
{
    while(true)
    {
        for (list<Motor *>::iterator it = LMotores.begin(); it != LMotores.end(); ++it)
            (*it)->RUN();
    }
}


