#ifndef MELETRICO_H
#define MELETRICO_H

#include "Motor.h"


class MEletrico : public Motor
{
    private:

    protected:

    public:
        MEletrico(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt);
        virtual ~MEletrico();
        bool RUN() { cout << "RUN ??"; return false; }
        bool START() { cout << "RUN ??"; return false; }
        bool RESTART() { cout << "RUN ??"; return false; }
        bool STOP() { cout << "RUN ??"; return false; }
        bool ESTOU_QUENTE() { cout << "RUN ??"; return false; }

        void show(ostream &f = std::cout)
        {
            f << "-----------------" << endl;
            f << Motor::getTIPO() << endl;
            f << "-----------------" << endl;
            Motor::show(f);
        }

};

#endif // MELETRICO_H
