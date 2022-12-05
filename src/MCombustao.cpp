#include "MCombustao.h"
#include "Fabrica.h"

MCombustao::MCombustao(int _id,string _marca,int _posicaoY,int _posicaoX,int _consumoHora,Fabrica *Pt)
:Motor(_id,_marca,_posicaoY,_posicaoX,_consumoHora,Pt)
{
    Objetos::setTIPO("MCombustao");
    setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
    int minVerde=getPt_Fabrica()->getDefinicaoMCombustao(0);
    int maxVerde=getPt_Fabrica()->getDefinicaoMCombustao(1);
    TEMPERATURA=Uteis::AleatorioDouble((double)minVerde,(double)maxVerde);
}

MCombustao::~MCombustao()
{

}


bool MCombustao::RUN()
{
    if(getESTADO() != ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << getTIPO()<< "\t" << getID() << "\t" << getESTADO() << "\t" << getCOR_MOTOR() << endl;
        Uteis::Delay(500);
        return false;
    }

    int minAmarelo=getPt_Fabrica()->getDefinicaoMCombustao(2);
    int minVermelho=getPt_Fabrica()->getDefinicaoMCombustao(4);
    int proAvaria=getPt_Fabrica()->getDefinicaoMCombustao(6);

    //passar uma hora fazer o que esta em baixo
//    int consumoHora=getCONSUMO();
//    consumoHora+=consumoHora;
//    setCONSUMO(consumoHora);
//    HORAS_TRABALHO++;


    if(Uteis::ProbabilidadeAcerto(proAvaria))
    {
        setESTADO(ESTADO_AVARIADO);
        ESTOU_AVARIADO();
        int nAvarias=getNumeroDeAvarias();
        nAvarias++;
        setNumeroDeAvarias(nAvarias);
    }

    if(TEMPERATURA >= minAmarelo)
    {
        setCOR_MOTOR(AMARELO);
        ESTOU_QUENTE();
    }

    if(TEMPERATURA >= minVermelho)
    {
        setCOR_MOTOR(VERMELHO);
        STOP();
    }

    cout << getTIPO();
    cout << "\t" << getID();
    cout << "\t" << getESTADO();
    cout << "\t" << getCOR_MOTOR();
    cout << fixed;
    cout.precision(2);
    cout << "\t\t" << TEMPERATURA<<endl;
    TEMPERATURA += Uteis::AleatorioDouble(0.1,1);
    Uteis::Delay(500);

    return true;
}

bool MCombustao::START()
{
    if (getESTADO() != ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao ID=[" << getID() << "] START" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        return true;
    }else
        cout << "MCombustao ID=[" << getID() << "] Ja esta RUN" << endl;
    return false;
}

bool MCombustao::RESTART()
{
    if (getESTADO() == ESTADO_MOTOR::ESTADO_RUN)
    {
        cout << "MCombustao ID=[" << getID() << "] RUN" << endl;
        cout << "MCombustao ID=[" << getID() << "] INICIAR RESTART" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        cout << "MCombustao ID=[" << getID() << "] PARADO" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_RUN);
        cout << "MCombustao ID=[" << getID() << "] RUN NOVAMENTE" << endl;
        return true;
    }else
        cout << "MCombustao ID=[" << getID() << "] Ja esta PARADO" << endl;
    return false;
}

bool MCombustao::STOP()
{
    if (getESTADO() != ESTADO_MOTOR::ESTADO_PARADO)
    {
        cout << "MCombustao ID=[" << getID() << "] STOP" << endl;
        setESTADO(ESTADO_MOTOR::ESTADO_PARADO);
        return true;
    }else
    {
        cout << "MCombustao ID=[" << getID() << "] Ja esta parado" << endl;
        return false;
    }
}

