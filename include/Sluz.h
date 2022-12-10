#ifndef SLUZ_H
#define SLUZ_H

#include <Sensor.h>

class Sluz : public Sensor
{
    private:

    protected:


    public:
        Sluz(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso,Fabrica *Pt);
        virtual ~Sluz();
        bool Run();
};

#endif // SLUZ_H
