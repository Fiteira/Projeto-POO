#include "MCombustao.h"

#include "Fabrica.h"

MCombustao::MCombustao(Fabrica *F, int _id, string _marca, int _posx, int _posy, float _consumo) : Motor(F, _id, _marca, _posx, _posy, _consumo)
{
    //ctor
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe MCombustao" << endl;
    Set_TEMP_AV_MCOMBUSTAO();
}

MCombustao::~MCombustao()
{
    //dtor
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe MCombustao" << endl;
}

bool MCombustao::RUN()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe MCombustao" << endl;
    if (Get_ESTADO() == ESTADO_MOTOR::ESTADO_START || Get_ESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        if (Get_ESTADO() == ESTADO_MOTOR::ESTADO_START)
            Set_ESTADO(ESTADO_MOTOR::ESTADO_RUN);
        if (Get_ESTADO() == ESTADO_MOTOR::ESTADO_RUN)
        {
            float Verde_Min = Get_Ptr_Fabrica()->Get_DEF_MCOMBUSTAO(0);
            float Verde_Max = Get_Ptr_Fabrica()->Get_DEF_MCOMBUSTAO(1);
            if (TEMPERATURA >= Verde_Min && TEMPERATURA <= Verde_Max)
                TEMPERATURA += Uteis::Numero_Aleatorio_Int((int)Verde_Min, (int)(Verde_Max / 4));
            else
                TEMPERATURA += Uteis::Numero_Aleatorio_Int(-(int)(Verde_Max / 4), 1);
            if (TEMPERATURA >= Verde_Min && TEMPERATURA <= Verde_Max)
                TEMPERATURA_VERDE();
            else if (TEMPERATURA >= TEMPERATURA_AVISO && TEMPERATURA <= Get_Ptr_Fabrica()->Get_DEF_MCOMBUSTAO(3))
                TEMPERATURA_AMARELO();
            else if (TEMPERATURA >= TEMPERATURA_PARAGEM && TEMPERATURA <= Get_Ptr_Fabrica()->Get_DEF_MCOMBUSTAO(5))
            {
                TEMPERATURA_VERMELHO();
                ESTOU_QUENTE();
            }
            else
                ESTOU_AVARIADO();
            float Avaria = Uteis::Numero_Aleatorio_Float(0, 100);
            if (Avaria < Get_PROBABILIDADE_AVARIA())
                ESTOU_AVARIADO();
            HORAS_TRABALHO += 0.1;
            cout << "ID = " << Get_ID() << ", Temperatura = " << TEMPERATURA << endl;
            return true;
        }
    }
    return false;
}

void MCombustao::SHOW()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe MCombustao" << endl;
    cout << "TIPO: [" << Get_TIPO() << "]" << endl;
    Motor::SHOW();
}
