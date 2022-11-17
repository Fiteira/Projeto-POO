#include <iostream>
using namespace std;

#include "Fabrica.h"


int main()
{


    User *U;

    U=new Visitante(2,"Visitante");
    U=new Normal(1,"Normal");
    U=new Admin(0,"Admin");

    Fabrica Fabrica_Minha_Terra(U,"Empresa-da-Minha-Terra",8,16,10,50,80,0,80,81,100,101,50,1,0,80,81,100,101,250,10,0,50,51,70,71,100,1);


    Fabrica_Minha_Terra.Add(U);

    return 0;
}
