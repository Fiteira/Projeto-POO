#include "Normal.h"

Normal::Normal(int _id,string _nome)
:User(_id,_nome)
{
    //ctor
}

Normal::~Normal()
{
    //dtor
}

void Normal::ADD()
{
    int id;
    string nome;

    cout << "-User Normal-"<< endl;
    cout << "ID: ";
    cin >> id;
    cout << "Nome: ";
    cin >> nome;

    Normal(id,nome);
}
