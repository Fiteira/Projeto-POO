#ifndef MCOMBUSTAO_H
#define MCOMBUSTAO_H

#include "Motor.h"


class MCombustao : public Motor
{
    private:

    protected:

    public:
        MCombustao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,float _temperatura);
        virtual ~MCombustao();
        bool RUN();
        bool START();
        bool RESTART();
        bool STOP();
        bool ESTOU_QUENTE();

};

#endif // MCOMBUSTAO_H
