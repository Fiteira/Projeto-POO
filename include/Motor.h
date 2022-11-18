#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Objetos.h"

class Motor : public Objetos
{
    public:
        Motor(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,float _temperatura);
        virtual ~Motor();
        virtual bool RUN() { cout << "RUN ??"; return false; }
        virtual bool START(){ cout << "START ??"; return false; }
        virtual bool RESTART(){ cout << "RESTART ??"; return false; }
        virtual bool STOP() { cout << "STOP ??"; return false; }
        virtual bool ESTOU_QUENTE(){ cout << "ESTOU_QUENTE ??"; return false; }


        //gets
        string getTipo(){return TIPO;}
        int getID(){return Objetos::getID();}

        //sets
        void setTipo(string tipo){TIPO=tipo;}

    protected:
        float TEMPERATURA;
    private:
        int CONSUMO_HORA;
        string TIPO;


};

#endif // MOTOR_H
