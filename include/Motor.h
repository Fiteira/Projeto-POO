#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <string>
using namespace std;

#include "Objetos.h"


enum ESTADO_MOTOR {STOP = 0, START, RUN,AVARIADO};

class Motor : public Objetos
{
    private:
    Fabrica *Ptr_Fabrica;
    ESTADO_MOTOR ESTADO;

    public:
        Motor();
        virtual ~Motor();
        virtual bool RUN() { cout << "RUN ??"; return false; }
        virtual bool STOP() { cout << "STOP ??"; return false; }
        virtual bool START() { cout << "START ??"; return false; }
        ESTADO_MOTOR Get_ESTADO() { return ESTADO; }
    protected:


};

#endif // MOTOR_H
