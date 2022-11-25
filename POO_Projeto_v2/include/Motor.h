#ifndef MOTOR_H
#define MOTOR_H

#include <Objeto.h>

#include <iostream>
#include <string>
#include <list>

using namespace std;

enum ESTADO_MOTOR {ESTADO_PARADO = 0, ESTADO_START, ESTADO_RUN, ESTADO_AVARIADO, ESTADO_INDEFENIDO};
enum TEMPERATURA_MOTOR {VERDE = 0, AMARELO, VERMELHO};

class Motor : public Objeto
{
    protected:
        float CONSUMO_HORA;
        float HORAS_TRABALHO;
        float TEMPERATURA;
        float TEMPERATURA_AVISO;
        float TEMPERATURA_PARAGEM;
        ESTADO_MOTOR ESTADO;
        TEMPERATURA_MOTOR TEMPERATURA_ESTADO;

    public:
        Motor(Fabrica *F, int _id, string _marca, int _posx, int _posy, float _consumo);
        virtual ~Motor();

        bool START();
        virtual bool RUN() { return false; }
        bool STOP();
        bool RESTART();
        bool ESTOU_QUENTE();
        bool ESTOU_AVARIADO();
        virtual void SHOW();

        virtual string Get_TIPO() { return "Motor"; }
        ESTADO_MOTOR Get_ESTADO() { return ESTADO; }
        float Get_TEMPERATURA() { return TEMPERATURA; }
        float Get_CONSUMO_HORA() { return CONSUMO_HORA; }
        float Get_HORAS_TRABALHO() { return HORAS_TRABALHO; }

        void Set_TEMP_AV_MCOMBUSTAO();
        void Set_TEMP_AV_MELETRICO();
        void Set_TEMP_AV_MINDUCAO();
        void Set_ESTADO(ESTADO_MOTOR EST) { ESTADO = EST; }
        void Set_TEMPERATURA(float t) { TEMPERATURA = t; }
        void Set_TEMPERATURA_MOTOR(TEMPERATURA_MOTOR EST) { TEMPERATURA_ESTADO = EST; }
        void TEMPERATURA_VERDE() { Set_TEMPERATURA_MOTOR(TEMPERATURA_MOTOR::VERDE); }
        void TEMPERATURA_AMARELO() { Set_TEMPERATURA_MOTOR(TEMPERATURA_MOTOR::AMARELO); }
        void TEMPERATURA_VERMELHO() { Set_TEMPERATURA_MOTOR(TEMPERATURA_MOTOR::VERMELHO); }
};

#endif // MOTOR_H
