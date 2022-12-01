#include <iostream>
#include <sstream>
using namespace std;
#include <ctime>

#include "Fabrica.h"
/*
void print(ostream &o) {
    o << "Hello World!";
    o << endl;
    o << "Hello World!1";
    o << endl;
    o << "Hello World!2";
}
*/

void teste()
{
    User *U;

    U=new Admin(0,"Admin");

    Fabrica *F=new Fabrica(U,"Empresa-da-Minha-Terra",8,16,10,50,80,0,80,81,100,101,50,1,0,80,81,100,101,250,10,0,50,51,70,71,100,1);
    U=new Normal(1,"Normal");
    F->Add(U);

    U=new Visitante(2,"Visitante");
    F->Add(U);


    Motor *M=new MCombustao(0,"XPTO",5,3,5,F);
    F->Add(M);
    M=new MCombustao(1,"XPTO1",2,3,5,F);
    F->Add(M);

    //F->Listar_Tipo("MCombustaoa",cout);
    F->Ligar(0);
    F->Ligar(1);
    //F->Listar(cout);
    F->Run();
    //F->Manutencao();
    //F->Stop();

    F->~Fabrica();
}

int main()
{
    /*
    stringstream ss;
    print(ss);
    string outputString = ss.str();
    cout << outputString << endl;
    */
    /*
    int hora;

    Uteis::HoraAtual(hora);

    cout << hora;
    */
    teste();
    return 0;
}
