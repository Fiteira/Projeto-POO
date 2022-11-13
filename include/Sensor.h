#ifndef SENSOR_H
#define SENSOR_H

#include "Objetos.h"

class Sensor : public Objetos
{
    public:
        Sensor();
        virtual ~Sensor();

    protected:

    private:
        int VALOR_AVISO;
};

#endif // SENSOR_H
