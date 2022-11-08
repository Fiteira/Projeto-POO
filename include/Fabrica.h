#ifndef FABRICA_H
#define FABRICA_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

#include "User.h"
#include "Motor.h"
#include "Sensor.h"


class Fabrica
{
    private:
    list<User *> LUsers;
    list<Motor*> LMotores;
    list<Sensor*> LSensores;

    User *Ut_Atual;

    string NOME_EMPRESA;
    string HORA_INICIO;
    string HORA_FECHO;
    string VIZINHANCA_AVISO;
    int DIMENSAO_FABRICA_X;
    int DIMENSAO_FABRICA_Y;

    public:
        Fabrica(User *ut);
        virtual ~Fabrica();
        bool Load(const string &ficheiro);
        bool Add(User *ut);
        bool Add(Motor *m);
    protected:




};

#endif // FABRICA_H
