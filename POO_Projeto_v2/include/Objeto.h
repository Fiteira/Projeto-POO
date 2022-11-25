#ifndef OBJETO_H
#define OBJETO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Fabrica;

class Objeto
{
    int ID;
    string MARCA;
    float PROBABILIDADE_AVARIA;
    int NUMERO_AVARIAS;
    int POS_X;
    int POS_Y;
    Fabrica *Ptr_Fabrica;

    public:
        Objeto(Fabrica *F, int _id, string _marca, int _posx, int _posy);
        virtual ~Objeto();

        string Get_TIPO() { return "Objeto"; }
        Fabrica *Get_Ptr_Fabrica() { return Ptr_Fabrica; }
        int Get_ID() { return ID; }
        string Get_MARCA() { return MARCA; }
        int Get_NUMERO_AVARIA() { return NUMERO_AVARIAS; }
        int Get_POS_X() { return POS_X; }
        int Get_POS_Y() { return POS_Y; }
        float Get_PROBABILIDADE_AVARIA() { return PROBABILIDADE_AVARIA; }

        void Set_ID(int _id) { ID = _id; }
        void Set_MARCA(string _marca) { MARCA = _marca; }
        void Set_PROBABILIDADE_AVARIA(float p) { PROBABILIDADE_AVARIA = p; }
        void Set_AVARIA() { NUMERO_AVARIAS++; }
        void Set_NUMERO_AVARIA(int av) { NUMERO_AVARIAS += av; }
        void Set_AVARIA_ZERO() { NUMERO_AVARIAS = 0; }
        void Set_POS_X(int _pos_x) { POS_X = _pos_x; }
        void Set_POS_Y(int _pos_y) { POS_Y = _pos_y; }
};

#endif // OBJETO_H
