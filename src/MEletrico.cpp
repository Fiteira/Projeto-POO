#include "MEletrico.h"

MEletrico::MEletrico(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,float _temperatura)
:Motor(_id,_marca,_posicaoY,_posicaoX,_consumoHora,_temperatura)
{
    //ctor
}

MEletrico::~MEletrico()
{
    //dtor
}
