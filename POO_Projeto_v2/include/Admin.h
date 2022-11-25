#ifndef ADMIN_H
#define ADMIN_H

#include <User.h>


class Admin : public User
{
    public:
        Admin(int _id, string _nome);
        virtual ~Admin();
        bool PossoADICIONAR() { return true; }
        bool PossoREMOVER() { return true; }
        bool PossoLISTAR() { return true; }
        bool PossoRUN() { return true; }
        bool PossoMANUTENCAO() { return true; }
};

#endif // ADMIN_H
