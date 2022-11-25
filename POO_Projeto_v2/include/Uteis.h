#ifndef UTEIS_H
#define UTEIS_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Uteis
{
    public:
        Uteis();
        virtual ~Uteis();
        static void Delay(int ms)
        {
            clock_t t1 = clock();
            while (clock() < t1 + ms);
        }

        static int Numero_Aleatorio_Int(int min, int max)
        {
            srand(time(NULL));
            return rand() % (max - min + 1) + min;
        }

        static float Numero_Aleatorio_Float(float min, float max)
        {
            float num = ((float) rand()) / (float) RAND_MAX;
            float dif = max - min;
            float res = num * dif;
            return min + res;
        }
};

#endif // UTEIS_H
