#ifndef FABRICA_H
#define FABRICA_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

#define DEF_MOTORES 7

// Filhos da classe User
#include "Admin.h"
#include "Normal.h"
#include "Visitante.h"

// Filhos da classe Motor
#include "MCombustao.h"

// Filhos da classe Sensor
//#include "SHumidade.h"

#include "Uteis.h"

class Fabrica
{
    string NOME_EMPRESA;
    int HORA_INICIO;
    int HORA_FECHO;
    float HORA;
    int VIZINHANCA_AVISO; // se houver sensor de humidade, que detete humidade, tipo maior que 10, a volta desse sensor desliga-se as maquinas (lança um aviso)
    int LARGURA;
    int COMPRIMENTO;
    //int *POS_MOTORES;
    //int *POS_SENSORES;
    float DEF_MCOMBUSTAO[DEF_MOTORES];
    float DEF_MELETRICO[DEF_MOTORES];
    float DEF_MINDUCAO[DEF_MOTORES];
    User *Ut_Atual;
    //Sensor *S_Disparou;
    list<User *> LUsers;
    list<Motor *> LMotores;
    list<Motor *> LMQuentes;
    list<Motor *> LMAvariados;
    //list<Sensor *> LSensores;

    public:
        Fabrica(User *ut);
        virtual ~Fabrica();

        bool Load(const string &ficheiro);
        bool Ut_Atual_Existe();
        bool Horas_Trabalho();
        bool Add(User *ut);
        bool Add(Motor *m);
        bool Rem_User(int id_ut);
        bool Rem_Motor(int id_motor);
        void Listar(ostream &f = std::cout);
        void Ligar_Motores();
        void Desligar_Motores();
        User* Pesquisa_User(int id_user);
        Motor* Pesquisa_Motor(int id_motor);
        void Ligar(int id_motor);
        void Desligar(int id_motor);
        ESTADO_MOTOR Get_Estado(int id_motor);
        list<Motor *> Listar_Tipo(string Tipo, ostream &f = std::cout);
        void ESTOU_QUENTE(Motor *M);
        void ESTOU_AVARIADO(Motor *M);
        void RUN();
        bool Manutencao();
        Objeto* Pesquisa_Objeto(list<Objeto *> &obj, string _marca);
        list<string> Ranking_Dos_Fracos();
        list<Motor *> Ranking_Dos_Mais_Trabalhadores();
        void Relatorio(string fich_xml);
        int Aviso_Humidade(list<Motor *> &lm);
        int Aviso_Fumo(list<Motor *> &lm, string fich_video);
        int Aviso_Luz(string fich_video);
        void Aviso_Missel(string fvideo, string festado);

        void Esvaziar_Limpar();

        float Get_DEF_MCOMBUSTAO(int pos) { return DEF_MCOMBUSTAO[pos]; }
        float Get_DEF_MELETRICO(int pos) { return DEF_MELETRICO[pos]; }
        float Get_DEF_MINDUCAO(int pos) { return DEF_MINDUCAO[pos]; }
};

#endif // FABRICA_H
