#include "MCombustao.h"

MCombustao::MCombustao(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _consumoHora,float _temperatura)
:Motor(_id,_marca,_posicaoY,_posicaoX,_probAvaria,_consumoHora,_temperatura)
{

}

MCombustao::~MCombustao()
{
    //dtor
}
