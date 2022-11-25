#ifndef NORMAL_H
#define NORMAL_H

#include <User.h>


class Normal : public User
{
    public:
        Normal(int _id, string _nome);
        virtual ~Normal();
        bool PossoADICIONAR() { return true; }
        bool PossoLISTAR() { return true; }
        bool PossoRUN() { return true; }
        bool PossoMANUTENCAO() { return true; }
};

#endif // NORMAL_H
