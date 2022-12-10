#include "Sensor.h"
#include "Fabrica.h"

Sensor::Sensor(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso,Fabrica *Pt)
:Objetos(_id,_marca,_posicaoY,_posicaoX,Pt)
{
    VALOR_AVISO=_valorAviso;
    VALOR_ATUAL=0;
}

Sensor::~Sensor()
{

}

bool Sensor::ESTOU_AVARIADO()
{
    if (!getPt_Fabrica())
        return false;

    getPt_Fabrica()->ESTOU_AVARIADO_SENSOR(this);
    return true;

}
