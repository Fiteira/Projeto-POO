#ifndef SENSOR_H
#define SENSOR_H

#include "Objetos.h"

class Sensor : public Objetos
{
    public:
        Sensor(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso);
        virtual ~Sensor();

    protected:

    private:
        int VALOR_AVISO;
};

#endif // SENSOR_H
