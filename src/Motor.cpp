#include "Motor.h"
#include "Fabrica.h"

Motor::Motor(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt)
:Objetos(_id,_marca,_posicaoY,_posicaoX,Pt)
{
    CONSUMO_HORA=_consumoHora;
}

Motor::~Motor()
{

}

bool Motor::ESTOU_QUENTE()
{
    if (!getPt_Fabrica())
        return false;

    getPt_Fabrica()->ESTOU_QUENTE(this);
    return true;
}

bool Motor::ESTOU_AVARIADO()
{
    if (!getPt_Fabrica())
        return false;

    getPt_Fabrica()->ESTOU_AVARIADO_MOTOR(this);
    return true;

}
