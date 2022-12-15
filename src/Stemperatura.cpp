#include "Stemperatura.h"
#include "Fabrica.h"

Stemperatura::Stemperatura(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso,Fabrica *Pt)
    :Sensor(_id,_marca,_posicaoY,_posicaoX,_probAvaria,_valorAviso,Pt)
{
    Objetos::setTIPO("Stemperatura");
}

Stemperatura::~Stemperatura()
{

}

bool Stemperatura::Run()
{
    int proAvaria=getProbAvaria();

    if(getESTADO() != ESTADO_SENSOR::RUN)
    {
        if(getPt_Fabrica()->UmaHora())
            getPt_Fabrica()->Manutencao();

        cout << getTIPO();
        cout << "\t" << getID();

        if(getESTADO() == 0)
            cout << "\t" << "RUN";
        else if (getESTADO() == 1)
            cout << "\t" << "AVARIADO";
        else
            cout << "\t" << "SEM_ESTADO";

        cout << "\t  " << getVALOR_AVISO();
        cout << "\t\t    " << getVALOR_ATUAL();

        cout << endl;
        Uteis::Delay(100);

        return false;
    }

    if(getPt_Fabrica()->UmaHora())
    {
        if(Uteis::ProbabilidadeAcerto(proAvaria))
        {
            setESTADO(AVARIADO);
            ESTOU_AVARIADO();
            int nAvarias=getNumeroDeAvarias();
            nAvarias++;
            setNumeroDeAvarias(nAvarias);
        }
    }

//    int valorAtual=Uteis::Aleatorio(1,99);
    int valorAtual=Uteis::Aleatorio(40,50);
    setVALOR_ATUAL(valorAtual);

    if(valorAtual == getVALOR_AVISO())
    {
        system("cls");
        list<Motor *> listaMotores;
        int nMotores;
        nMotores=getPt_Fabrica()->Aviso_Humidade(listaMotores,getPOSICAO_X(),getPOSICAO_Y(),2);

        cout << "Foram " << nMotores << " desligados por causa do sensor de Temperatura ID: " << getID() << "  Posicao X:"<<getPOSICAO_X()<<" Y:"<<getPOSICAO_Y()<< endl << endl;


        for (list<Motor *>::iterator it = listaMotores.begin(); it != listaMotores.end(); ++it)
        {

            cout << "TIPO: " << (*it)->getTIPO();
            cout << "| ID: " << (*it)->getID();
            cout << "| MARCA: " << (*it)->getMARCA();
            cout << "| X: " << (*it)->getPOSICAO_X();
            cout << "| Y: " << (*it)->getPOSICAO_Y() << endl;

        }

        Uteis::Liberar_Memoria(&listaMotores);

        while(!kbhit());
        getPt_Fabrica()->Menu();
        return false;
    }


    cout << getTIPO();
    cout << "\t" << getID();

    if(getESTADO() == 0)
        cout << "\t" << "RUN";
    else if (getESTADO() == 1)
        cout << "\t" << "AVARIADO";
    else
        cout << "\t" << "SEM_ESTADO";

    cout << "\t  " << getVALOR_AVISO();
    cout << "\t\t    " << getVALOR_ATUAL();

    cout << endl;
    Uteis::Delay(100);

    return true;
}
