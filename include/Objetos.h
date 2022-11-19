#ifndef OBJETOS_H
#define OBJETOS_H


#include <iostream>
#include <string>
#include "Uteis.h"

using namespace std;

class Fabrica;
class Objetos
{
    private:
        int ID;
        string MARCA;
        int POSICAO_Y;
        int POSICAO_X;
        float PROB_AVARIA;

    protected:

    public:
        Objetos(int _id,string _marca,int _posicaoY,int _posicaoX);
        virtual ~Objetos();

        //gets
        int getID(){return ID;}
        string getMARCA(){return MARCA;}
        int getPOSICAO_Y(){return POSICAO_Y;}
        int getPOSICAO_X(){return POSICAO_X;}
        float getPROB_AVARIA(){return PROB_AVARIA;}





};

#endif // OBJETOS_H
