#ifndef FABRICA_H
#define FABRICA_H

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

#include "User.h"
#include "Motor.h"
#include "Sensor.h"
#include "Objetos.h"
#include "XML.h"

#define NVALORES 6

enum ESTADO_MOTOR {STOP = 0, START, RUN,AVARIADO};

class Fabrica
{

    public:
        Fabrica(User *ut);
        Fabrica(string _nomeEmpresa,int _horaInicio,int _horaFecho,int _vizinhancaAviso,int _dimensaoX,
                int _dimensaoY,int ME_verde_min,int ME_verde_max,int ME_amarelo_min,int ME_amarelo_max,
                int ME_vermelho_min,int ME_vermelho_max,int ME_probAvaria,int MC_verde_min,int MC_verde_max,
                int MC_amarelo_min,int MC_amarelo_max,int MC_vermelho_min,int MC_vermelho_max,int MC_probAvaria,
                int MI_verde_min,int MI_verde_max,int MI_amarelo_min,int MI_amarelo_max,int MI_vermelho_min,
                int MI_vermelho_max,int MI_probAvaria);
        virtual ~Fabrica();
        bool Load(const string &ficheiro);
        bool Add(User *ut);
        bool Add(Motor *m);
        void Listar(ostream &f = std::cout);
        void Desligar(int id_motor);
        ESTADO_MOTOR Get_ESTADO(int id_motor) { return ESTADO; }
        list<Motor *> *Listar_Tipo(string Tipo, ostream &f = std::cout);
        bool Manutencao();
        list<string> *Ranking_Dos_Fracos();
        list<Motor *> *Ranking_Dos_Mais_Trabalhadores();
        void Relatorio(string fich_xml);
        int Aviso_Humidade(list<Motor *> &lm);
        int Aviso_Fumo(list<Motor *> &lm, string fich_video);
        int Aviso_Luz(string fich_video);
        void Aviso_Missel(string fvideo, string festado = "Estado.txt");

    protected:

    private:
    list<User *> LUsers;
    list<Motor*> LMotores;
    list<Sensor*> LSensores;
    list<Objetos*> LObjetos;

    User *Ut_Atual;
    ESTADO_MOTOR ESTADO;

    string NOME_EMPRESA;
    int HORA_INICIO;
    int HORA_FECHO;
    int VIZINHANCA_AVISO;
    int DIMENSAO_FABRICA_X;
    int DIMENSAO_FABRICA_Y;

    int DEFI_MELETRICO[NVALORES];
    int DEFI_MCOMBUSTAO[NVALORES];
    int DEFI_MINDUCAO[NVALORES];

};

#endif // FABRICA_H
