#include "Objetos.h"

Objetos::Objetos(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria)
{
    ID=_id;
    MARCA=_marca;
    POSICAO_Y=_posicaoY;
    POSICAO_X=_posicaoX;
    PROB_AVARIA=_probAvaria;
}

Objetos::~Objetos()
{
    //dtor
}
