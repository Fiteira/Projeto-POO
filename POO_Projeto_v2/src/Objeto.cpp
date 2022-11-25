#include "Objeto.h"

#include "Fabrica.h"

Objeto::Objeto(Fabrica *F, int _id, string _marca, int _posx, int _posy)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Objeto" << endl;
    //ctor
    Ptr_Fabrica = F;
    ID = _id;
    MARCA = _marca;
    PROBABILIDADE_AVARIA = -1;
    NUMERO_AVARIAS = 0;
    POS_X = _posx;
    POS_Y = _posy;
}

Objeto::~Objeto()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Objeto" << endl;
    //dtor
}
