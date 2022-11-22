#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Objetos.h"

enum ESTADO_MOTOR {ESTADO_PARADO = 0, ESTADO_RUN, ESTADO_AVARIADO};
enum TEMPERATURA_COR {VERDE, AMARELO, VERMELHO};

class Motor : public Objetos
{
    private:
        int CONSUMO_HORA;
        string TIPO;
        ESTADO_MOTOR ESTADO;
        TEMPERATURA_COR COR_MOTOR;

    protected:
        float TEMPERATURA;

    public:
        Motor(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt);
        virtual ~Motor();
        virtual bool RUN() { cout << "RUN ??"; return false; }
        virtual bool START(){ cout << "START ??"; return false; }
        virtual bool RESTART(){ cout << "RESTART ??"; return false; }
        virtual bool STOP() { cout << "STOP ??"; return false; }
        virtual bool ESTOU_QUENTE(){ cout << "ESTOU_QUENTE ??"; return false; }

        virtual void show(ostream &f = std::cout)
        {
            Objetos::show(f);
            f << "CONSUMO_HORA: " << CONSUMO_HORA << endl;
        }


        //gets
        int getCONSUMO(){return CONSUMO_HORA;}
        string getTIPO(){return TIPO;}
        ESTADO_MOTOR getESTADO() { return ESTADO; }
        TEMPERATURA_COR getCOR_MOTOR() { return COR_MOTOR; }
        float getTEMPERATURA(){return TEMPERATURA;}

        //sets
        void setCONSUMO(int CONSUMO){CONSUMO_HORA = CONSUMO;}
        void setTIPO(string tipo){TIPO = tipo;}
        void setESTADO(ESTADO_MOTOR EST) { ESTADO = EST; }
        void setCOR_MOTOR(TEMPERATURA_COR COR) { COR_MOTOR = COR; }





};

#endif // MOTOR_H
