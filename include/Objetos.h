#ifndef OBJETOS_H
#define OBJETOS_H


#include <iostream>
#include <string>


using namespace std;

class Fabrica;
class Objetos
{
    public:
        Objetos(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria);
        virtual ~Objetos();

    protected:

    private:
        int ID;
        string MARCA;
        int POSICAO_Y;
        int POSICAO_X;
        float PROB_AVARIA;

};

#endif // OBJETOS_H
