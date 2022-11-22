#include "MIndocao.h"

MIndocao::MIndocao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt)
:Motor(_id,_marca,_posicaoY,_posicaoX,_consumoHora,Pt)
{
    Motor::setTIPO("MIndocao");
}

MIndocao::~MIndocao()
{

}
