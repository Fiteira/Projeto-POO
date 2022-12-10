#ifndef SENSOR_H
#define SENSOR_H

#include "Objetos.h"

enum ESTADO_SENSOR {RUN, AVARIADO,SEMESTADO=-1};

class Sensor : public Objetos
{
    private:
        ESTADO_SENSOR ESTADO;
        int VALOR_AVISO;
        int VALOR_ATUAL;
        float _probAvaria;

    protected:

    public:
        Sensor(int _id,string _marca,int _posicaoY,int _posicaoX,float _probAvaria,int _valorAviso,Fabrica *Pt);
        virtual ~Sensor();
        virtual bool Run() { cout << "RUN ??"; return false; }
        bool ESTOU_AVARIADO();

    //get
    int getVALOR_AVISO(){return VALOR_AVISO;}
    int getVALOR_ATUAL(){return VALOR_ATUAL;}
    ESTADO_SENSOR getESTADO() { return ESTADO; }

    //sets
    void setVALOR_AVISO(int valorAviso){VALOR_AVISO = valorAviso;}
    void setVALOR_ATUAL(int valorAtual){VALOR_ATUAL = valorAtual;}
    void setESTADO(ESTADO_SENSOR EST) { ESTADO = EST; }
};

#endif // SENSOR_H
