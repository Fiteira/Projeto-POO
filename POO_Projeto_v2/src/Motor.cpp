#include "Motor.h"

#include "Fabrica.h"

Motor::Motor(Fabrica *F, int _id, string _marca, int _posx, int _posy, float _consumo) : Objeto(F, _id, _marca, _posx, _posy)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Motor" << endl;
    //ctor
    CONSUMO_HORA = _consumo;
    ESTADO = ESTADO_PARADO;
    HORAS_TRABALHO = 0;
    TEMPERATURA = 0;
    TEMPERATURA_ESTADO = VERDE;
}

Motor::~Motor()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Motor" << endl;
    //dtor
}

void Motor::Set_TEMP_AV_MCOMBUSTAO()
{
    TEMPERATURA_AVISO = Get_Ptr_Fabrica()->Get_DEF_MCOMBUSTAO(2);
    TEMPERATURA_PARAGEM = Get_Ptr_Fabrica()->Get_DEF_MCOMBUSTAO(4);
    Set_PROBABILIDADE_AVARIA(Get_Ptr_Fabrica()->Get_DEF_MCOMBUSTAO(6));
}

void Motor::Set_TEMP_AV_MELETRICO()
{
    TEMPERATURA_AVISO = Get_Ptr_Fabrica()->Get_DEF_MELETRICO(2);
    TEMPERATURA_PARAGEM = Get_Ptr_Fabrica()->Get_DEF_MELETRICO(4);
    Set_PROBABILIDADE_AVARIA(Get_Ptr_Fabrica()->Get_DEF_MELETRICO(6));
}

void Motor::Set_TEMP_AV_MINDUCAO()
{
    TEMPERATURA_AVISO = Get_Ptr_Fabrica()->Get_DEF_MINDUCAO(2);
    TEMPERATURA_PARAGEM = Get_Ptr_Fabrica()->Get_DEF_MINDUCAO(4);
    Set_PROBABILIDADE_AVARIA(Get_Ptr_Fabrica()->Get_DEF_MINDUCAO(6));
}

bool Motor::START()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Motor" << endl;
    Set_ESTADO(ESTADO_MOTOR::ESTADO_START);
    return true;
}

bool Motor::STOP()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Motor" << endl;
    Set_ESTADO(ESTADO_MOTOR::ESTADO_PARADO);
    return true;
}

bool Motor::RESTART()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Motor" << endl;
    STOP();
    START();
    return true;
}

bool Motor::ESTOU_QUENTE()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Motor" << endl;
    if (Get_Ptr_Fabrica())
    {
        Get_Ptr_Fabrica()->ESTOU_QUENTE(this);
        return true;
    }
    return false;
}

bool Motor::ESTOU_AVARIADO()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Motor" << endl;
    if (Get_Ptr_Fabrica())
    {
        Get_Ptr_Fabrica()->ESTOU_AVARIADO(this);
        return true;
    }
    return false;
}

void Motor::SHOW()
{
    cout << "ID: [" << Get_ID() << "]" << endl;
    cout << "MARCA: [" << Get_MARCA() << "]" << endl;
    cout << "CONSUMO_HORA: [" << CONSUMO_HORA << "]" << endl;
    cout << "HORAS_TRABALHO: [" << HORAS_TRABALHO << "]" << endl;
    cout << "ESTADO: [" << ESTADO << "]" << endl;
    cout << "TEMPERATURA: [" << TEMPERATURA << "]" << endl;
    cout << "TEMPERATURA_ESTADO: [" << TEMPERATURA_ESTADO << "]" << endl;
}
