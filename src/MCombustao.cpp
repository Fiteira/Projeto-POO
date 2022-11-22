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
    if (getESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao... RUN : ID= " << Objetos::getID() << endl;
        cout << "ESTADO: " << getESTADO() << endl;
        cout << "TEMPERATURA= " << getTEMPERATURA() << endl;
        TEMPERATURA += 0.1f;
        Uteis::Delay(500);
    }else
        setESTADO(ESTADO_RUN);
    return true;
}

bool MCombustao::START()
{
    if (getESTADO() != ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao.... START" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        return true;
    }else
        cout << "MCombustao....Ja esta RUN" << endl;
    return false;
}

bool MCombustao::RESTART()
{
    if (getESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao.... RUN" << endl;
        cout << "MCombustao.... INICIAR RESTART" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        cout << "MCombustao.... PARADO" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        cout << "MCombustao.... RUN NOVAMENTE" << endl;
        return true;
    }else
        cout << "MCombustao....Ja esta PARADO" << endl;
    return false;
}

bool MCombustao::STOP()
{
    if (getESTADO() != ESTADO_MOTOR::ESTADO_PARADO)
    {
        cout << "MCombustao.... STOP" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        return true;
    }else
    {
        cout << "MCombustao....Ja esta parado" << endl;
        return false;
    }
}

bool MCombustao::ESTOU_QUENTE()
{
    return true;
}
