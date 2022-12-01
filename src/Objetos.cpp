#include "Objetos.h"

Objetos::Objetos(int _id,string _marca,int _posicaoY,int _posicaoX,Fabrica *F)
{
    ID=_id;
    MARCA=_marca;
    POSICAO_Y=_posicaoY;
    POSICAO_X=_posicaoX;
    Pt_Fabrica=F;
    numeroDeAvarias=0;
}

Objetos::~Objetos()
{

}

void Objetos::show(ostream &f)
{
    f << "ID: " << ID << endl;
    f << "MARCA: " << MARCA << endl;
    f << "POSICAO_Y: " << POSICAO_Y << endl;
    f << "POSICAO_X: " << POSICAO_X << endl;
}
