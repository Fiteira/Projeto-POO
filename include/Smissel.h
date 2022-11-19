#ifndef SMISSEL_H
#define SMISSEL_H

#include <Sensor.h>


class Smissel : public Sensor
{
    private:

    protected:

    public:
        Smissel(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso);
        virtual ~Smissel();

};

#endif // SMISSEL_H
