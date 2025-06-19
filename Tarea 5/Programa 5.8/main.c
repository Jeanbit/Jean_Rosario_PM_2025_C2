#include <stdio.h>
#define TAM 100

void Imprime(int Primos[], int T);
void Primo(int A, int *B);

int main(void)
{
    int P[TAM] = {2};
    int FLA, J = 1, PRI = 3;

    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);

        if (FLA)
        {
            P[J] = PRI;
            J++;
        }

        PRI += 2;
    }

    Imprime(P, TAM);
    return 0;
}


void Primo(int A, int *B)
{
    int DI = 3;
    if (A % 2 == 0)
    {
        *B = 0;
        return;
    }

    while (*B && DI * DI <= A)
    {
        if (A % DI == 0)
            *B = 0;
        DI += 2;
    }
}


void Imprime(int Primos[], int T)
{
    for (int I = 0; I < T; I++)
    {
        printf("Primos[%d]: %d\n", I, Primos[I]);
    }
}
