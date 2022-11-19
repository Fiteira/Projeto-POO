#include "Fabrica.h"
#include "Uteis.h"

/** \brief Construtor da Fabrica, sendo dado o USER actual
 *
 * \param   User autal
 * \author LD & GA
 * \return Fabrica
 *
 */
Fabrica::Fabrica(User *ut)
{
    Ut_Atual = ut;
    LUsers.push_back(ut);
}

/** \brief Construtor da Fabrica, sendo dado o USER actual
 *
 * \param _nomeEmpresa _horaInicio, _horaFecho, _vizinhancaAviso, _dimensaoX, _dimensaoY, ME_verde_min, ME_verde_max, ME_amarelo_min, ME_amarelo_max, ME_vermelho_min,
 * \param ME_vermelho_max, ME_probAvaria, MC_verde_min, MC_verde_max, MC_amarelo_min, MC_amarelo_max, MC_vermelho_min, MC_vermelho_max, MC_probAvaria, MI_verde_min, MI_verde_max, MI_amarelo_min
 * \param MI_amarelo_max, MI_vermelho_min, MI_vermelho_max, MI_probAvaria
 * \author LD & GA
 * \return Fabrica
 *
 */
Fabrica::Fabrica(User *ut,string _nomeEmpresa,int _horaInicio,int _horaFecho,int _vizinhancaAviso,int _dimensaoX,
int _dimensaoY,int ME_verde_min,int ME_verde_max,int ME_amarelo_min,int ME_amarelo_max,
int ME_vermelho_min,int ME_vermelho_max,int ME_probAvaria,int MC_verde_min,int MC_verde_max,
int MC_amarelo_min,int MC_amarelo_max,int MC_vermelho_min,int MC_vermelho_max,int MC_probAvaria,
int MI_verde_min,int MI_verde_max,int MI_amarelo_min,int MI_amarelo_max,int MI_vermelho_min,
int MI_vermelho_max,int MI_probAvaria)
{

    Ut_Atual = ut;
    LUsers.push_back(ut);

    NOME_EMPRESA=_nomeEmpresa;
    HORA_INICIO=_horaInicio;
    HORA_FECHO=_horaFecho;
    VIZINHANCA_AVISO=_vizinhancaAviso;
    DIMENSAO_FABRICA_X=_dimensaoX;
    DIMENSAO_FABRICA_Y=_dimensaoY;

    //DEFENICOES PARA O MOTOR ELETRICO
    DEFI_MELETRICO[0]=ME_verde_min;
    DEFI_MELETRICO[1]=ME_verde_max;
    DEFI_MELETRICO[2]=ME_amarelo_min;
    DEFI_MELETRICO[3]=ME_amarelo_max;
    DEFI_MELETRICO[4]=ME_vermelho_min;
    DEFI_MELETRICO[5]=ME_vermelho_max;
    DEFI_MELETRICO[6]=ME_probAvaria;

    //DEFENICOES PARA O MOTOR COMBUSTAO
    DEFI_MCOMBUSTAO[0]=MC_verde_min;
    DEFI_MCOMBUSTAO[1]=MC_verde_max;
    DEFI_MCOMBUSTAO[2]=MC_amarelo_min;
    DEFI_MCOMBUSTAO[3]=MC_amarelo_max;
    DEFI_MCOMBUSTAO[4]=MC_vermelho_min;
    DEFI_MCOMBUSTAO[5]=MC_vermelho_max;
    DEFI_MCOMBUSTAO[6]=MC_probAvaria;

    //DEFENICOES PARA O MOTOR INDUCAO
    DEFI_MINDUCAO[0]=MI_verde_min;
    DEFI_MINDUCAO[1]=MI_verde_max;
    DEFI_MINDUCAO[2]=MI_amarelo_min;
    DEFI_MINDUCAO[3]=MI_amarelo_max;
    DEFI_MINDUCAO[4]=MI_vermelho_min;
    DEFI_MINDUCAO[5]=MI_vermelho_max;
    DEFI_MINDUCAO[6]=MI_probAvaria;
}

/** \brief Destrutor da Fabrica
 *
 * \author LD & GA
 *
 */

Fabrica::~Fabrica()
{

    cout << "Passei em <" << __FUNCTION__ << ">" << endl;

    Uteis::Liberar_Memoria(&LUsers);
    Uteis::Liberar_Memoria(&LMotores);
    Uteis::Liberar_Memoria(&LSensores);
    Uteis::Liberar_Memoria(&LObjetos);

}

/** \brief As configurações da Fábrica são dadas em ficheiro XML, com todas as informações
 *
 * \param ficheiro XML
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Load(const string &ficheiro)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
    return true;
}

/** \brief Adicionar Utilizadores (ter em atenção as regras!)
 *
 * \param User adicionado
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Add(User *ut)
{
    if (!Ut_Atual)
    {
        cout << "Nao existe User Atual!" << endl;
        return false;
    }
    else{
        if (!Ut_Atual->PossoADD())
        {
            cout << "Nao tens autorizacao!!!" << endl;
            return false;
        }else
        {
            if(ut)
            {
                LUsers.push_back(ut);
                return true;
            }else
            {
                cout << "Nao existe User!" << endl;
                return false;
            }
        }
    }
}

/** \brief Adicionar Motores (Ver quem pode!)
 *
 * \param Motor adicionado
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Add(Motor *M)
{
    if (!Ut_Atual)
    {
        cout << "Nao existe User Atual!" << endl;
        return false;
    }
    else{
        if (!Ut_Atual->PossoADD())
        {
            cout << "Nao tens autorizacao!!!" << endl;
            return false;
        }else
        {
            if(M)
            {
                LObjetos.push_back(M);
                LMotores.push_back(M);
                return true;
            }else
            {
                cout << "Nao existe Motor!" << endl;
                return false;
            }
        }
    }
}


/** \brief Listar o estado atual da fábrica;
 *
 * \param output no &f
 * \author LD & GA
 * \return void
 *
 */
void Fabrica::Listar(ostream &f)
{
    cout << "Passei em <" << __FUNCTION__ << ">" << endl;
}




/** \brief Desligar um motor especifico, dado o seu ID;
 *
 * \param ID Motor
 * \author LD & GA
 * \return void
 *
 */
void Fabrica::Desligar(int id_motor)
{

}


/** \brief Saber o estado de um dado Motor, dado o seu ID;
 *
 * \param ID Motor
 * \author LD & GA
 * \return ESTADO_MOTOR
 *
 */
/*
ESTADO_MOTOR Fabrica::Get_Estado(int id_motor)
{

    return Motor::Get_ESTADO();
}
*/


/** \brief Listar e devolver todos os Motores de um dado Tipo;
 *
 * \param string Tipo e output no &f
 * \author LD & GA
 * \return lista Motores
 *
 */
list<Motor *> *Fabrica::Listar_Tipo(string Tipo, ostream &f)
{
    return NULL;
}


















/*
bool Fabrica::Run()
{
    while(true)
    {
        for (list<Motor *>::iterator it = LMotores.begin(); it != LMotores.end(); ++it)
            (*it)->RUN();
    }
}
*/

