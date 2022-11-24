#include "MCombustao.h"


MCombustao::MCombustao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt)
:Motor(_id,_marca,_posicaoY,_posicaoX,_consumoHora,Pt)
{
    Motor::setTIPO("MCombustao");
    setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
}

MCombustao::~MCombustao()
{

}


bool MCombustao::RUN()
{
    if(getESTADO() != ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao ID=[" << getID() << "] Motor desligado" << endl;
        return false;
    }

    cout << "MCombustao ID=[" << getID() << "] RUN" << endl;
    cout << "ESTADO: " << getESTADO() << endl;
    cout << "TEMPERATURA= " << getTEMPERATURA() << endl;
    TEMPERATURA += 0.1f;
    Uteis::Delay(500);

    return true;
}

bool MCombustao::START()
{
    if (getESTADO() != ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao ID=[" << getID() << "] START" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        return true;
    }else
        cout << "MCombustao ID=[" << getID() << "] Ja esta RUN" << endl;
    return false;
}

bool MCombustao::RESTART()
{
    if (getESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao ID=[" << getID() << "] RUN" << endl;
        cout << "MCombustao ID=[" << getID() << "] INICIAR RESTART" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        cout << "MCombustao ID=[" << getID() << "] PARADO" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        cout << "MCombustao ID=[" << getID() << "] RUN NOVAMENTE" << endl;
        return true;
    }else
        cout << "MCombustao ID=[" << getID() << "] Ja esta PARADO" << endl;
    return false;
}

bool MCombustao::STOP()
{
    if (getESTADO() != ESTADO_MOTOR::ESTADO_PARADO)
    {
        cout << "MCombustao ID=[" << getID() << "] STOP" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        return true;
    }else
    {
        cout << "MCombustao ID=[" << getID() << "] Ja esta parado" << endl;
        return false;
    }
}

