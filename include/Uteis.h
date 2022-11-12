#ifndef UTEIS_H
#define UTEIS_H

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include<vector>
using namespace std;

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include<unistd.h>


class Uteis
{

    public:
        Uteis();
        virtual ~Uteis();

        static void Delay(int ms)
        {
            int microsecond = 1000;
            usleep(ms * microsecond);
        }

        static int Aleatorio(int _min,int _max)
        {
            return _min + rand()%(_max - _min + 1);
        }

		static void Msg(string txt)
        {
            cout << txt << endl;
        }

        static bool LerVector(int *V,int N)
        {
            cout<<"Funcao Por Fazer<"<<__FUNCTION__<< ">" << endl;
            return true;
        }

        static void CopiarVetor(int *x,int *y,int n)
        {
            for(int i=0;i<n;i++)
            {
                y[i]=x[i];
            }
        }

        static void MostrarVector(int *V,int N)
        {
            cout << "{";
            for(int i=0;i<N;i++)
                cout << V[i] << ";";
            cout << "}";
        }

        static bool GerarAleatorioVector(int *V,int N)
        {
            for(int i=0;i<N;i++)
            {
                V[i]=rand()%100;
            }
            return true;
        }

        static int LerInteiro(string txt)
        {
            cout << txt;
            int X;
            cin >> X;
            return X;
        }

        static void SepararStr(string const &str, const char tipo,vector<string> &out)
        {
            stringstream s(str);

            string s2;
            while (getline(s, s2, tipo) )
            {
                out.push_back(s2);
            }
        }

        static bool ProbabilidadeAcerto(int n)
        {
            srand(time(NULL));
            int numero=rand()%100;
            if(numero <= (n-1))
                return true;
            else
                return false;
        }

};

#endif // UTEIS_H
