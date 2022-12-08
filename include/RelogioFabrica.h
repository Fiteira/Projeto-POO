#ifndef RELOGIOFABRICA_H
#define RELOGIOFABRICA_H


#include <iostream>
using namespace std;
#include <time.h>

class RelogioFabrica
{
    time_t START;
    int VELOCIDADE;
public:
    RelogioFabrica(int Vel = 1)
    {
        VELOCIDADE = Vel;
        START = time(0);
    };
    time_t GetTime()
    {
        time_t NOW = time(0);
        time_t Simulada = START + (NOW - START) * VELOCIDADE;
        return Simulada;
    }
};



#endif // RELOGIOFABRICA_H
