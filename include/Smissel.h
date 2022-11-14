#ifndef SMISSEL_H
#define SMISSEL_H

#include <Sensor.h>


class Smissel : public Sensor
{
    public:
        Smissel(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso);
        virtual ~Smissel();

    protected:

    private:
};

#endif // SMISSEL_H
