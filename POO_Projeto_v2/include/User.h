#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
    int ID;
    string NOME;

    public:
        User(int _id, string _nome);
        virtual ~User();
        virtual bool PossoADICIONAR() { cout << "Nao tens permissoes para adicionar" << endl; return false; }
        virtual bool PossoREMOVER() { cout << "Nao tens permissoes para remover" << endl;return false; }
        virtual bool PossoLISTAR() { cout << "Nao tens permissoes para listar" << endl;return false; }
        virtual bool PossoRUN() { cout << "Nao tens permissoes para fazer run" << endl;return false; }
        virtual bool PossoMANUTENCAO() { cout << "Nao tens permissoes para fazer a manutencao" << endl; return false; }
        int Get_ID() { return ID; }
};

#endif // USER_H
