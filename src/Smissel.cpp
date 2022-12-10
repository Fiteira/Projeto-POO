#include "Smissel.h"

Smissel::Smissel(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso,Fabrica *Pt)
:Sensor(_id,_marca,_posicaoY,_posicaoX,_probAvaria,_valorAviso,Pt)
{
    Objetos::setTIPO("Sensor Missel");
}

Smissel::~Smissel()
{

}

bool Smissel::Run()
{
    return false;
}
