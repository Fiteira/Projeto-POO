#include "Sensor.h"

Sensor::Sensor(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso,Fabrica *Pt)
:Objetos(_id,_marca,_posicaoY,_posicaoX,Pt)
{
    VALOR_AVISO=_valorAviso;
}

Sensor::~Sensor()
{

}
