#include "Fabrica.h"
#include "Uteis.h"
#include <conio.h>
#include <string.h>

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
    Uteis::Liberar_Memoria(&LMotoresAvariados);
    Uteis::Liberar_Memoria(&LMotoresQuentes);
    Uteis::Liberar_Memoria(&LSensoresAvariados);
    LObjetos.clear();

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
    if(!Ut_Atual->PossoADD())
    {
        cout << "Nao tens autorizacao!!!" << endl;
        return false;
    }

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
    if(!Ut_Atual->PossoADD())
    {
        cout << "Nao tens autorizacao!!!" << endl;
        return false;
    }

    if(!ut)
    {
        cout << "Nao existe User!" << endl;
        return false;
    }

    LUsers.push_back(ut);
    return true;


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

    if(!Ut_Atual->PossoADD())
    {
        cout << "Nao tens autorizacao!!!" << endl;
        return false;
    }
    if(!M)
    {
        cout << "Nao existe Motor!" << endl;
        return false;
    }
    if(M->getPOSICAO_X()>getDIMENSAO_FABRICA_X() || M->getPOSICAO_X()>getDIMENSAO_FABRICA_X())
    {
        cout << "O motor nao pode ficar fora da fabrica" << endl;
        return false;
    }

    list<Objetos *>::iterator it;
    for (it = LObjetos.begin(); it != LObjetos.end(); ++it)
    {
        if((*it)->getPOSICAO_Y() == M->getPOSICAO_Y() && (*it)->getPOSICAO_X() == M->getPOSICAO_X())
        {
            cout << "Tem um objeto nessa posicao" << endl;
            return false;
        }
    }
    LObjetos.push_back(M);
    LMotores.push_back(M);
    return true;

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
    if(!Ut_Atual->PossoLISTAR())
        return;

    list<Objetos *>::iterator it;
    for (it = LObjetos.begin(); it != LObjetos.end(); ++it)
        (*it)->show(f);
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
    list<Motor *>::iterator it;
    int n=0;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {
        if((*it)->getID() == id_motor)
        {
            (*it)->setESTADO(ESTADO_PARADO);
            n=1;
        }
    }
    if(n==0)
    {
        cout << "Nao tem nenhum motor com esse ID:[" << id_motor <<"]" << endl;
    }
}


/** \brief Saber o estado de um dado Motor, dado o seu ID;
 *
 * \param ID Motor
 * \author LD & GA
 * \return ESTADO_MOTOR
 *
 */
ESTADO_MOTOR Fabrica::Get_ESTADO(int id_motor)
{
    list<Motor *>::iterator it;
    int n=0;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {

        if((*it)->getID() == id_motor)
            return (*it)->getESTADO();
    }

    if(n==0)
    {
        cout << "Nao tem nenhum motor com esse ID:[" << id_motor <<"]" << endl;
        return ESTADO_MOTOR::SEM_ESTADO;
    }
}


/** \brief Listar e devolver todos os Motores de um dado Tipo;
 *
 * \param string Tipo e output no &f
 * \author LD & GA
 * \return lista Motores
 *
 */
list<Motor *> Fabrica::Listar_Tipo(string Tipo, ostream &f)
{
    list<Motor *> listaMotores;

    if(!Ut_Atual->PossoLISTAR())
        return listaMotores;

    list<Motor *>::iterator it;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {
        if((*it)->getTIPO().compare(Tipo) == 0)
        {
            listaMotores.push_back((*it));
            (*it)->show(f);
        }
    }
    if (listaMotores.empty())
        cout << "Nao tem nenhum Motor com esse tipo" << endl;
    return listaMotores;
}

/** \brief Manutenção de todos os dispositivos (Motores e Sensores!), A manutenção de um motor poderá ser
 *         por exemplo alterar a temperatura para um valor (aleatório) dentro da temperatura VERDE do motor;
 * \param
 * \author LD & GA
 * \return true / false
 *
 */
bool Fabrica::Manutencao()
{
    if (LMotoresQuentes.empty())
        cout << "Nao tem nenhum Motor Quente" << endl;
    if (LMotoresAvariados.empty())
        cout << "Nao tem nenhum Motor Avariados" << endl;
    if (LSensoresAvariados.empty())
        cout << "Nao tem nenhum Sensores Avariados" << endl;

    return true;
}



/** \brief Quais as Marcas de motores/sensores que mais avariam, deve devolver uma lista (ordenada) do que
 *          mais avaria para o mais fiável
 * \param
 * \author LD & GA
 * \return lista das Marcas de motores/sensores
 *
 */
list<string> Fabrica::Ranking_Dos_Fracos()
{

    list<string> Marcas;
    if(!Ut_Atual->PossoLISTAR())
        return Marcas;

    return Marcas;
}

/** \brief Quais motores que mais trabalharam, deve devolver uma lista (ordenada);
 *
 * \param
 * \author LD & GA
 * \return lista dos Motores
 *
 */
list<Motor *> Fabrica::Ranking_Dos_Mais_Trabalhadores()
{
     list<Motor *> listaMotores;
     if(!Ut_Atual->PossoLISTAR())
        return listaMotores;
}


/** \brief Enviar um relatório em XML, do estado da fábrica;
 *          O relatório deverá ter a informação do total de consumo (do motor) nesse dia;
 * \param
 * \author LD & GA
 * \return
 *
 */
void Fabrica::Relatorio(string fich_xml)
{

}


/** \brief Quando um sensor de Humidade envia um aviso, todos os motores que estão numa dada vizinhança
*           (X) dele devem ser desligados!, o método deve devolver (por parametro) a lista dos Motores que
*            foram desligados, também deve devolver o número de motores que foram desligados;
* \param   devolver a lista dos Motores
* \author LD & GA
* \return int
*
*/
int Fabrica::Aviso_Humidade(list<Motor *> &lm)
{
    return 0;
}

/** \brief Quando um sensor de FUMO envia um aviso, todos os motores devem ser desligados e deve ser
 *           invocado um video mostrando as zonas de saída da fábrica;
 * \param   devolver a lista dos Motores e video
 * \author LD & GA
 * \return int
 *
 */
int Fabrica::Aviso_Fumo(list<Motor *> &lm, string fich_video)
{
    return 0;
}

/** \brief No caso de o sensor de LUZ enviar um aviso (por exemplo quando a luz é inferior a um dado valor!)
 *           deve passar um video desejando um bom regresso a casa!, pois o tempo está a escurecer e aproximase a
 *           hora de dormir.
 * \param   video
 * \author LD & GA
 * \return int
 *
 */
int Fabrica::Aviso_Luz(string fich_video)
{
    return 0;
}

/** \brief No caso de o sensor de MÍSSEL enviar um aviso (por exemplo quando o valor for 1) deve passar um
 *   video mostrando os abrigos e a fábrica deve desligar-se completamente, guardando o estado atual!.
 *
 * \param   video, ficheiro de testo
 * \author LD & GA
 * \return
 *
 */
void Fabrica::Aviso_Missel(string fvideo, string festado)
{

    ofstream f(festado);
    Listar(f);
    f.close();
    Stop();
    //falta o video
}



//-----------------------Funcoes Extras------------------------//

/** \brief Desligar motores
 *
 * \param
 * \author LD & GA
 * \return void
 *
 */
bool Fabrica::Stop()
{
    if(!Ut_Atual->PossoRUN())
        return false;
    cout << "Fabrica a desligar Motores" << endl;
    list<Motor *>::iterator it;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
        (*it)->STOP();
    return true;
}


/** \brief Run motores
 *
 * \param
 * \author LD & GA
 * \return void
 *
 */
bool Fabrica::Run()
{
    if(!Ut_Atual->PossoRUN())
        return false;
    do
    {
        system("cls");
        for (list<Motor *>::iterator it = LMotores.begin(); it != LMotores.end(); ++it)
        {
            if(TempoFabrica() == false)
                return false;
            (*it)->RUN();
        }
    }
    while(!kbhit());
    //ir para o menu
    printf( "\ntecla clicada '%c' \n", _getch());
    return true;
}

void Fabrica::Ligar(int id_motor)
{
     if(!Ut_Atual->PossoRUN())
        return;
    list<Motor *>::iterator it;
    int n=0;
    for (it = LMotores.begin(); it != LMotores.end(); ++it)
    {
        if((*it)->getID() == id_motor)
        {
            (*it)->setESTADO(ESTADO_RUN);
            n=1;
        }
    }
    if(n==0)
    {
        cout << "Nao tem nenhum motor com esse ID:[" << id_motor <<"]" << endl;
    }
}

bool Fabrica::ESTOU_QUENTE(Motor *M)
{
    LMotoresQuentes.push_back(M);
    return true;
}

bool Fabrica::ESTOU_AVARIADO_MOTOR(Motor *M)
{
    LMotoresAvariados.push_back(M);
    return true;
}

bool Fabrica::ESTOU_AVARIADO_SENSOR(Sensor *S)
{
    LSensoresAvariados.push_back(S);
    return true;
}

bool Fabrica::TempoFabrica()
{
    int hora;
    Uteis::HoraAtual(hora);

    if(hora<getHoraInicio() || hora>getHoraFecho())
    {
        Stop();
        return false;
    }
    else
        return true;
}
