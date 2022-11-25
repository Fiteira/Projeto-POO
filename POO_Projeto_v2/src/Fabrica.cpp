#include "Fabrica.h"

Fabrica::Fabrica(User *ut)
{
    //ctor
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    HORA = 0;
    HORA_INICIO = 0;
    HORA_FECHO = 1;
    Ut_Atual = ut;
    Add(ut);
}

Fabrica::~Fabrica()
{
    //dtor
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
}

bool Fabrica::Load(const string &ficheiro)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    NOME_EMPRESA = "Empresa da Minha Terra";
    HORA_INICIO = 8;
    HORA_FECHO = 16;
    VIZINHANCA_AVISO = 10;
    LARGURA = 50;
    COMPRIMENTO = 80;
    /*POS_MOTORES = new int[LARGURA * COMPRIMENTO];
    POS_SENSORES = new int[LARGURA * COMPRIMENTO];
    int tam = LARGURA * COMPRIMENTO;
    for (int i = 0; i < tam; i++)
    {
        POS_MOTORES[i] = -1;
        POS_SENSORES[i] = -1;
    }*/
    DEF_MCOMBUSTAO[0] = 0;
    DEF_MCOMBUSTAO[1] = 80;
    DEF_MCOMBUSTAO[2] = 81;
    DEF_MCOMBUSTAO[3] = 100;
    DEF_MCOMBUSTAO[4] = 101;
    DEF_MCOMBUSTAO[5] = 250;
    DEF_MCOMBUSTAO[6] = 10;
    DEF_MELETRICO[0] = 0;
    DEF_MELETRICO[1] = 80;
    DEF_MELETRICO[2] = 81;
    DEF_MELETRICO[3] = 100;
    DEF_MELETRICO[4] = 101;
    DEF_MELETRICO[5] = 500;
    DEF_MELETRICO[6] = 1;
    DEF_MINDUCAO[0] = 0;
    DEF_MINDUCAO[1] = 50;
    DEF_MINDUCAO[2] = 51;
    DEF_MINDUCAO[3] = 70;
    DEF_MINDUCAO[4] = 71;
    DEF_MINDUCAO[5] = 100;
    DEF_MINDUCAO[6] = 1;
    // COMPLETAR
    return false;
}

bool Fabrica::Ut_Atual_Existe()
{
    if (Ut_Atual)
        return true;
    cout << "A fabrica nao tem gestor" << endl;
    return false;
}

bool Fabrica::Horas_Trabalho()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        HORA += 0.1;
        if (HORA < (HORA_FECHO - HORA_INICIO))
            return true;
        else
        {
            cout << "Nao e possivel executar a operacao, a Fabrica vai fechar, e hora de ir embora!!!" << endl;
            Desligar_Motores();
            Esvaziar_Limpar();
            exit(1);
        }
    }
    return false;
}

bool Fabrica::Add(User *ut)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            if (Ut_Atual->PossoADICIONAR())
            {
                LUsers.push_back(ut);
                return true;
            }
        }
    }
    return false;
}

bool Fabrica::Add(Motor *m)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            if (Ut_Atual->PossoADICIONAR())
            {
                LMotores.push_back(m);
                return true;
            }
        }
    }
    return false;
}

bool Fabrica::Rem_User(int id_ut)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            if (Ut_Atual->PossoREMOVER())
            {
                // remove o user da fabrica
                User *U = Pesquisa_User(id_ut);
                if (U != NULL)
                {
                    LUsers.remove(U);
                    delete(U);
                    return true;
                }
                cout << "User nao foi encontrado" << endl;
            }
        }
    }
    return false;
}

bool Fabrica::Rem_Motor(int id_motor)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            if (Ut_Atual->PossoREMOVER())
            {
                // remove o motor da fabrica
                Motor *M = Pesquisa_Motor(id_motor);
                if (M != NULL)
                {
                    LMotores.remove(M);
                    delete(M);
                    return true;
                }
                cout << "Motor nao foi encontrado" << endl;
            }
        }
    }
    return false;
}

void Fabrica::Listar(ostream &f)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            list<Motor *>::iterator it;
            for (it = LMotores.begin(); it != LMotores.end(); ++it)
            {
                f << "ID;" << (*it)->Get_ID() << endl;
                f << "MARCA;" << (*it)->Get_MARCA() << endl;
                f << "ESTADO_MOTOR;" << (*it)->Get_ESTADO() << endl;
                f << "TEMPERATURA;" << (*it)->Get_TEMPERATURA() << endl;
                f << "COMSUMO_HORA;" << (*it)->Get_CONSUMO_HORA() << endl;
                f << "HORAS_TRABALHO;" << (*it)->Get_HORAS_TRABALHO() << endl;
                f << "N_AVARIAS;" << (*it)->Get_NUMERO_AVARIA() << endl;
            }
        }
    }
}

void Fabrica::Ligar_Motores()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            list<Motor *>::iterator it;
            for (it = LMotores.begin(); it != LMotores.end(); ++it)
                (*it)->START();
        }
    }
}

void Fabrica::Desligar_Motores()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        list<Motor *>::iterator it;
        for (it = LMotores.begin(); it != LMotores.end(); ++it)
            (*it)->STOP();
    }
}

User* Fabrica::Pesquisa_User(int id_user)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            list<User *>::iterator it;
            for (it = LUsers.begin(); it != LUsers.end(); ++it)
            {
                if (id_user == (*it)->Get_ID())
                    return (*it);
            }
        }
    }
    return NULL;
}

Motor* Fabrica::Pesquisa_Motor(int id_motor)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            list<Motor *>::iterator it;
            for (it = LMotores.begin(); it != LMotores.end(); ++it)
            {
                if (id_motor == (*it)->Get_ID())
                    return (*it);
            }
        }
    }
    return NULL;
}

void Fabrica::Ligar(int id_motor)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            Motor *M = Pesquisa_Motor(id_motor);
            if (M != NULL)
                M->START();
            else
                cout << "Motor nao existe" << endl;
        }
    }
}

void Fabrica::Desligar(int id_motor)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
    if (Ut_Atual_Existe())
        {
            Motor *M = Pesquisa_Motor(id_motor);
            if (M != NULL)
                M->STOP();
            else
                cout << "Motor nao existe" << endl;
        }
    }
}

ESTADO_MOTOR Fabrica::Get_Estado(int id_motor)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            Motor *M = Pesquisa_Motor(id_motor);
            if (M != NULL)
                return M->Get_ESTADO();
            else
                cout << "Motor nao existe" << endl;
        }
    }
    return ESTADO_MOTOR::ESTADO_INDEFENIDO;
}

list<Motor *> Fabrica::Listar_Tipo(string Tipo, ostream &f)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    list<Motor *> lista;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            list<Motor *>::iterator it;
            for (it = LMotores.begin(); it != LMotores.end(); ++it)
            {
                if ((*it)->Get_TIPO().compare(Tipo) == 0)
                {
                    lista.push_back((*it));
                    f << "ID;" << (*it)->Get_ID() << endl;
                    f << "MARCA;" << (*it)->Get_MARCA() << endl;
                    f << "ESTADO_MOTOR;" << (*it)->Get_ESTADO() << endl;
                    f << "TEMPERATURA;" << (*it)->Get_TEMPERATURA() << endl;
                    f << "COMSUMO_HORA;" << (*it)->Get_CONSUMO_HORA() << endl;
                    f << "HORAS_TRABALHO;" << (*it)->Get_HORAS_TRABALHO() << endl;
                    f << "N_AVARIAS;" << (*it)->Get_NUMERO_AVARIA() << endl;
                }
            }
        }
    }
    return lista;
}

void Fabrica::ESTOU_QUENTE(Motor *M)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        // Se M ja esta na lista nao deixo inserir
        list<Motor *>::iterator it;
        it = find(LMQuentes.begin(), LMQuentes.end(), M);
        if (it == LMQuentes.end()) // if (it == NULL)
        { // LMQuentes.end() aponta para NULL
            M->STOP();
            LMQuentes.push_back(M);
        }
    }
}

void Fabrica::ESTOU_AVARIADO(Motor *M)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        // Se M ja esta na lista nao deixo inserir
        list<Motor *>::iterator it;
        it = find(LMAvariados.begin(), LMAvariados.end(), M);
        if (it == LMAvariados.end()) // if (it == NULL)
        { // LMAvariados.end() aponta para NULL
            M->STOP();
            M->Set_AVARIA();
            LMAvariados.push_back(M);
        }
    }
}

void Fabrica::RUN()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        if (Ut_Atual->PossoRUN())
        {
            while(true)
            {
                if (Horas_Trabalho())
                {
                    list<Motor *>::iterator it;
                    for (it = LMotores.begin(); it != LMotores.end(); ++it)
                        (*it)->RUN();
                    //cout << "NAvisos-TEMP = " << LMQuentes.size() << endl;
                    if (LMQuentes.size() > 0 || LMAvariados.size() > 0)
                        Manutencao();
                    Uteis::Delay(1000);
                }
            }
        }
    }
}

bool Fabrica::Manutencao()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        if (Ut_Atual->PossoMANUTENCAO())
        {
            list<Motor *>::iterator it;
            for (it = LMQuentes.begin(); it != LMQuentes.end(); ++it)
            {
                (*it)->Set_TEMPERATURA(0);
                (*it)->TEMPERATURA_VERDE();
                (*it)->START();
            }
            LMQuentes.clear();
            for (it = LMAvariados.begin(); it != LMAvariados.end(); ++it)
            {
                (*it)->Set_TEMPERATURA(0);
                (*it)->TEMPERATURA_VERDE();
                (*it)->START();
            }
            LMAvariados.clear();
            return true;
        }
    }
    return false;
}

Objeto* Fabrica::Pesquisa_Objeto(list<Objeto *> &obj, string _marca)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        list<Objeto *>::iterator it;
        for (it = obj.begin(); it != obj.end(); ++it)
        {
            if ((*it)->Get_MARCA().compare(_marca) == 0)
                return (*it);
        }
    }
    return NULL;
}

list<string> Fabrica::Ranking_Dos_Fracos()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    list<string> lista;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            if (Ut_Atual->PossoLISTAR())
            {
                list<string>::iterator itl;
                list<Objeto *> obj;
                list<Objeto *>::iterator ito;
                Objeto *O;
                list<Motor *>::iterator itm;
                // mete na lista lista as marcas de todos os motores
                for (itm = LMotores.begin(); itm != LMotores.end(); ++itm)
                    lista.push_back((*itm)->Get_MARCA());
                // ordena a lista lista para depois poder retirar os duplicados
                lista.sort();
                // tira os duplicados da lista lista
                lista.unique();
                // adiciona a lista obj o objeto com as marcas da lista lista
                for (itl = lista.begin(); itl != lista.end(); ++itl)
                {
                    O = new Objeto(this, -1, (*itl), -1, -1);
                    obj.push_back(O);
                }
                // procura e define o numero de avarias em cada marca
                for (itm = LMotores.begin(); itm != LMotores.end(); ++itm)
                {
                    if ((*itm)->Get_NUMERO_AVARIA() > 0)
                    {
                        O = Pesquisa_Objeto(obj, (*itm)->Get_MARCA());
                        if (O)
                            O->Set_NUMERO_AVARIA((*itm)->Get_NUMERO_AVARIA());
                    }
                }
                // ordena a lista de objetos pelo numero de avarias descrescente
                obj.sort([](Objeto *A, Objeto *B)
                {
                     return A->Get_NUMERO_AVARIA() > B->Get_NUMERO_AVARIA();
                });
                // limpa a lista lista
                lista.clear();
                // adiciona as marcas(ordenadas pelo numero de avarias) na lista lista e liberta a memoria
                for (ito = obj.begin(); ito != obj.end(); ++ito)
                {
                    lista.push_back((*ito)->Get_MARCA());
                    delete (*ito);
                }
                obj.clear();
            }
        }
    }
    return lista;
}

list<Motor *> Fabrica::Ranking_Dos_Mais_Trabalhadores()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    list<Motor *> lista;
    if (Horas_Trabalho())
    {
        if (Ut_Atual_Existe())
        {
            if (Ut_Atual->PossoLISTAR())
            {
                lista = LMotores; // copia a lista LMotores para a lista lista
                // ordena a lista de motores pelo numero de horas descrescente
                lista.sort([](Motor *A, Motor *B)
                {
                     return A->Get_HORAS_TRABALHO() > B->Get_HORAS_TRABALHO();
                });
            }
        }
    }
    return lista;
}

void Fabrica::Relatorio(string fich_xml)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        if (Ut_Atual->PossoLISTAR())
        {
            // COMPLETAR - Goncalo
        }
    }
}

int Fabrica::Aviso_Humidade(list<Motor *> &lm)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        list<Motor *>::iterator it;
        //int x0 = S_Disparou->Get_POS_X();
        //int y0 = S_Disparou->Get_POS_Y();
        int x = 0, x0 = 0;
        int y = 0, y0 = 0;
        for (it = LMotores.begin(); it != LMotores.end(); ++it)
        {
            if (sqrt(pow((x - x0), 2) + pow((y - y0), 2)) < VIZINHANCA_AVISO)
            {
                Desligar((*it)->Get_ID());
                lm.push_back((*it));
            }
        }
        //S_Disparou = NULL;
        return 1;
    }
    return 0;
}

int Fabrica::Aviso_Fumo(list<Motor *> &lm, string fich_video)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        list<Motor *>::iterator it;
        for (it = LMotores.begin(); it != LMotores.end(); ++it)
        {
            Desligar((*it)->Get_ID());
            lm.push_back((*it));
        }
        system("fich_video");
        //S_Disparou = NULL;
        return 1;
    }
    return 0;
}

int Fabrica::Aviso_Luz(string fich_video)
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        system("fich_video");
        //S_Disparou = NULL;
        return 1;
    }
    return 0;
}

void Fabrica::Aviso_Missel(string fvideo, string festadoo = "Estado.txt")
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        Listar(cout);
        ofstream F(festadoo);
        Listar(F);
        F.close();
        Desligar_Motores();
        //S_Disparou = NULL;
    }
}

void Fabrica::Esvaziar_Limpar()
{
    cout << "Passei no metodo <" << __FUNCTION__ << "> na classe Fabrica" << endl;
    if (Ut_Atual_Existe())
    {
        if (Ut_Atual->PossoREMOVER())
        {
            list<Motor *>::iterator itm;
            //list<Sensor *>::iterator its;
            list<User *>::iterator itu;
            for(itm = LMotores.begin(); itm != LMotores.end(); ++itm)
                delete (*itm);
            LMotores.clear();
            for(itm = LMQuentes.begin(); itm != LMQuentes.end(); ++itm)
                delete (*itm);
            LMQuentes.clear();
            for(itm = LMAvariados.begin(); itm != LMAvariados.end(); ++itm)
                delete (*itm);
            LMAvariados.clear();
            /*for(its = LSensores.begin(); its != LSensores.end(); ++its)
                delete (*its);
            LSensores.clear();*/
            for(itu = LUsers.begin(); itu != LUsers.end(); ++itu)
                delete (*itu);
            LUsers.clear();
        }
    }
}
