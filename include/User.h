#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class Fabrica;
class User
{
    public:
        User();
        virtual ~User();
        virtual bool PossoLISTAR() {return false;}
        virtual bool PossoMANUTENCAO() { return false; }
        virtual bool PossoRUN() { return false; }
        virtual bool PossoREMOVER() { return false; }
        virtual bool PossoADD() { return false; }

    protected:

    private:
        int ID;
        string nome;
};

#endif // USER_H
