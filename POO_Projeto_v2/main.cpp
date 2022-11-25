#include <iostream>

using namespace std;

#include "Fabrica.h"

int main()
{
    cout << "Hello world!" << endl;

    User *U = new Admin(1, "Ruben Ferreira");
    Fabrica Gestor(U);
    Gestor.Add(U);
    Gestor.Load("ola.xml");
    MCombustao *MC = new MCombustao(&Gestor, 1, "AUDI", -1, -1, 10.3);
    Gestor.Add(MC);
    Gestor.Ligar_Motores();
    Gestor.RUN();
    /*Gestor.RUN();
    MC = new MCombustao(&Gestor, 2, "BMW", -1, -1, 15.8);
    Gestor.Add(MC);
    MC->Set_NUMERO_AVARIA(7);
    Gestor.Ligar(2);
    MC = new MCombustao(&Gestor, 3, "AUDI", -1, -1, 15.8);
    Gestor.Add(MC);
    MC->Set_NUMERO_AVARIA(6);
    Gestor.Ligar(3);
    MC = new MCombustao(&Gestor, 4, "AUDI", -1, -1, 15.8);
    Gestor.Add(MC);
    MC->Set_NUMERO_AVARIA(30);
    Gestor.Ligar(4);
    Gestor.RUN();
    Gestor.RUN();
    MC->SHOW();
    MC = new MCombustao(&Gestor, 5, "MERCEDES", -1, -1, 15.8);
    Gestor.Add(MC);
    MC->Set_NUMERO_AVARIA(15);
    MC = new MCombustao(&Gestor, 6, "AUDI", -1, -1, 15.8);
    Gestor.Add(MC);
    MC = new MCombustao(&Gestor, 7, "BMW", -1, -1, 15.8);
    Gestor.Add(MC);
    MC->Set_NUMERO_AVARIA(1);
    list<Motor *> lista = Gestor.Ranking_Dos_Mais_Trabalhadores();
    list<Motor *>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it)
    {
        cout << (*it)->Get_ID() << endl;
        cout << (*it)->Get_HORAS_TRABALHO() << endl << endl;
    }
    list<string> lista = Gestor.Ranking_Dos_Fracos();
    cout << "Tamanho da lista: " << lista.size() << endl;
    list<string>::iterator it;
    for (it = lista.begin(); it != lista.end(); ++it)
    {
        /*cout << (*it)->Get_ID() << endl;
        cout << (*it)->Get_MARCA() << endl;
        cout << (*it)->Get_NUMERO_AVARIA() << endl << endl;
        //cout << (*it) << endl << endl;
    }*/
    //Gestor.Rem_Motor(1);
    //Gestor.Esvaziar_Limpar();

    return 0;
}
