#include "Sluz.h"

Sluz::Sluz(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso,Fabrica *Pt)
:Sensor(_id,_marca,_posicaoY,_posicaoX,_probAvaria,_valorAviso,Pt)
{
    Objetos::setTIPO("Sensor Luz");
}

Sluz::~Sluz()
{

}

bool Sluz::Run()
{
    return false;
}
