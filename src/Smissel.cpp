#include "Smissel.h"
#include "Fabrica.h"

Smissel::Smissel(int _id,string _marca,int _posicaoY,int _posicaoX,int _probAvaria,int _valorAviso,Fabrica *Pt)
    :Sensor(_id,_marca,_posicaoY,_posicaoX,_probAvaria,_valorAviso,Pt)
{
    Objetos::setTIPO("Smissel");
}

Smissel::~Smissel()
{

}

bool Smissel::Run()
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

    int valorAtual=Uteis::Aleatorio(1,103-Uteis::Aleatorio(1,100));
    setVALOR_ATUAL(valorAtual);

    cout << getTIPO();
    cout << "\t\t" << getID();

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
