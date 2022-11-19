#include "MCombustao.h"

MCombustao::MCombustao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,float _temperatura)
:Motor(_id,_marca,_posicaoY,_posicaoX,_consumoHora,_temperatura)
{
    Motor::setTipo("MCombustao");
    Set_ESTADO(ESTADO_MOTOR::ESTADO_PARADO);
}

MCombustao::~MCombustao()
{

}


bool MCombustao::RUN()
{
    cout << "MCombustao... RUN : ID= " << Objetos::getID() << endl;
    cout << "ESTADO: " << Get_ESTADO() << endl;
    if (Get_ESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "TEMPERATURA= " << getID() << endl;
        TEMPERATURA += 0.1f;
        Uteis::Delay(500);
    }
    return true;
}

bool MCombustao::START()
{
    if (Get_ESTADO() != ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao.... START" << endl;
        Set_ESTADO(ESTADO_MOTOR::ESTADO_RUN);
        return true;
    }else
        cout << "MCombustao....Ja esta RUN" << endl;
    return false;
}

bool MCombustao::RESTART()
{
    if (Get_ESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao.... RUN" << endl;
        cout << "MCombustao.... INICIAR RESTART" << endl;
        Set_ESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        cout << "MCombustao.... PARADO" << endl;
        Set_ESTADO(ESTADO_MOTOR::ESTADO_RUN);
        cout << "MCombustao.... RUN NOVAMENTE" << endl;
        return true;
    }else
        cout << "MCombustao....Ja esta PARADO" << endl;
    return false;
}

bool MCombustao::STOP()
{
    if (Get_ESTADO() != ESTADO_MOTOR::ESTADO_PARADO)
    {
        cout << "MCombustao.... STOP" << endl;
        Set_ESTADO(ESTADO_MOTOR::ESTADO_PARADO);
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
