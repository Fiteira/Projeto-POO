#ifndef VISITANTE_H
#define VISITANTE_H

#include <User.h>


class Visitante : public User
{
    public:
        Visitante(int _id,string _nome);
        virtual ~Visitante();
        virtual bool PossoLISTAR() {return true;}

    protected:

    private:
};

#endif // VISITANTE_H
