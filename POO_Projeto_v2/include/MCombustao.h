#ifndef MCOMBUSTAO_H
#define MCOMBUSTAO_H

#include <Motor.h>


class MCombustao : public Motor
{
    public:
        MCombustao(Fabrica *F, int _id, string _marca, int _posx, int _posy, float _consumo);
        virtual ~MCombustao();

        bool RUN();
        void SHOW();

        string Get_TIPO() { return "MCombustao"; }
};

#endif // MCOMBUSTAO_H
