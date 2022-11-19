#ifndef MINDOCAO_H
#define MINDOCAO_H

#include "Motor.h"


class MIndocao : public Motor
{
    private:

    protected:

    public:
        MIndocao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,float _temperatura);
        virtual ~MIndocao();
        bool RUN() { cout << "RUN ??"; return false; }
        bool START() { cout << "RUN ??"; return false; }
        bool RESTART() { cout << "RUN ??"; return false; }
        bool STOP() { cout << "RUN ??"; return false; }
        bool ESTOU_QUENTE() { cout << "RUN ??"; return false; }


};

#endif // MINDOCAO_H
