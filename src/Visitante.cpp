#include "Visitante.h"

Visitante::Visitante(int _id,string _nome)
:User(_id,_nome)
{
    //ctor
}

Visitante::~Visitante()
{
    //dtor
}

void Visitante::ADD()
{
    int id;
    string nome;

    cout << "-User Visitante-"<< endl;
    cout << "ID: ";
    cin >> id;
    cout << "Nome: ";
    cin >> nome;

    Visitante(id,nome);
}
