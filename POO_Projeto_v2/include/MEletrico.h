#ifndef MELETRICO_H
#define MELETRICO_H

#include <Motor.h>


class MEletrico : public Motor
{
    public:
        MEletrico(Fabrica *F, int _id, string _marca, int _posx, int _posy, float _consumo);
        virtual ~MEletrico();

        bool RUN();
        void SHOW();

        string Get_TIPO() { return "MEletrico"; }
};

#endif // MELETRICO_H
