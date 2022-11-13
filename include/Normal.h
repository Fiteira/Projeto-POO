#ifndef NORMAL_H
#define NORMAL_H

#include "User.h"


class Normal : public User
{
    public:
        Normal();
        virtual ~Normal();
        bool PossoLISTAR() {return true;}
        bool PossoMANUTENCAO() { return true; }
        bool PossoRUN() { return true; }
        bool PossoADD() { return true; }

    protected:

    private:
};

#endif // NORMAL_H
