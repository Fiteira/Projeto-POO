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

    Fabrica *F=new Fabrica(U,"Empresa-da-Minha-Terra",8,16,10,50,80,0,80,81,100,101,500,1,0,80,81,100,101,250,10,0,50,51,70,71,100,1);
    U=new Normal(1,"Normal");
    F->Add(U);

    U=new Visitante(2,"Visitante");
    F->Add(U);


    Motor *M=new MCombustao(100,"Roy",20,10,5,F);
    F->Add(M);
    M=new MCombustao(101,"HIRTH-SOLO",10,0,3,F);
    F->Add(M);
    M=new MCombustao(102,"F200",22,15,4,F);
    F->Add(M);
    M=new MEletrico(103,"EFACEC",18,10,1250,F);
    F->Add(M);
//    M=new MInducao(4,"XPTO4",7,8,5,F);
//    F->Add(M);


    Sensor *S=new Stemperatura(200,"M1",40,12,1,50,F);
    F->Add(S);
    S=new Stemperatura(201,"M1",10,12,5,50,F);
    F->Add(S);
    S=new Sfogo(202,"M1",4,2,15,1,F);
    F->Add(S);
    S=new Smissel(300,"Molotof-Expresso",79,49,3,1,F);
    F->Add(S);

//    S=new Sluz(8,"XPTO8",1,8,4,1,F);
//    F->Add(S);



    F->LigarMotores();

    F->Run();

    delete(F);
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
