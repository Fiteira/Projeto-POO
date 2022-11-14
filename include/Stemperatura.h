#ifndef STEMPERATURA_H
#define STEMPERATURA_H

#include <Sensor.h>


class Stemperatura : public Sensor
{
    public:
        Stemperatura(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso);
        virtual ~Stemperatura();

    protected:

    private:
};

#endif // STEMPERATURA_H
