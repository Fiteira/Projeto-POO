#include "Motor.h"

Motor::Motor(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt)
:Objetos(_id,_marca,_posicaoY,_posicaoX,Pt)
{
    CONSUMO_HORA=_consumoHora;
}

Motor::~Motor()
{

}

