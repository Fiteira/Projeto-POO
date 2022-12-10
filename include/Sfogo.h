#ifndef SFOGO_H
#define SFOGO_H

#include <Sensor.h>


class Sfogo : public Sensor
{
    private:

    protected:

    public:
        Sfogo(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso,Fabrica *Pt);
        virtual ~Sfogo();
    bool Run();
};

#endif // SFOGO_H
