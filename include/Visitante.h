#ifndef VISITANTE_H
#define VISITANTE_H

#include "User.h"


class Visitante : public User
{
    public:
        Visitante();
        virtual ~Visitante();
        virtual bool PossoLISTAR() {return true;}
    protected:

    private:
};

#endif // VISITANTE_H
