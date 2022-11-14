#ifndef SFOGO_H
#define SFOGO_H

#include <Sensor.h>


class Sfogo : public Sensor
{
    public:
        Sfogo(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso);
        virtual ~Sfogo();

    protected:

    private:
};

#endif // SFOGO_H
