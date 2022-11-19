#ifndef SENSOR_H
#define SENSOR_H

#include "Objetos.h"

class Sensor : public Objetos
{
    private:
        int VALOR_AVISO;
        float _probAvaria;

    protected:

    public:
        Sensor(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso);
        virtual ~Sensor();

};

#endif // SENSOR_H
