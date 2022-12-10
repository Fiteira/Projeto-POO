#ifndef STEMPERATURA_H
#define STEMPERATURA_H

#include <Sensor.h>


class Stemperatura : public Sensor
{
    private:

    protected:

    public:
        Stemperatura(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso,Fabrica *Pt);
        virtual ~Stemperatura();
    bool Run();

};

#endif // STEMPERATURA_H
