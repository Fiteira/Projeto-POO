#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"


class Admin : public User
{
    public:
        Admin();
        virtual ~Admin();
        bool PossoLISTAR() {return true;}
        bool PossoMANUTENCAO() { return true; }
        bool PossoRUN() { return true; }
        bool PossoREMOVER() { return true; }
        bool PossoADD() { return true; }

    protected:

    private:
};

#endif // ADMIN_H
