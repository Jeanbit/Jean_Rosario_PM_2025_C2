#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void Lectura(int *A, int T);
void Imprime(int *A, int T);
void Elimina(int *A, int *T);

int main(void)
{
    int TAM;
    int ARRE[MAX];

    do
    {
        printf("Ingrese el tamano del arreglo (1-100): ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1);

    {
        Lectura(ARRE, TAM);
        Elimina(ARRE, &TAM);
        Imprime(ARRE, TAM);
    }

}


void Lectura(int A[], int T)
{
    printf("\n--- Lectura del arreglo ---\n");
    for (int I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}


void Imprime(int A[], int T)
{
    printf("\n--- Arreglo sin duplicados ---\n");
    for (int I = 0; I < T; I++)
    {
        printf("A[%d]: %d\n", I, A[I]);
    }
}


void Elimina(int A[], int *T)
{
    int I = 0, K, L;

    while (I < (*T - 1))
    {
        K = I + 1;
        while (K < *T)
        {
            if (A[I] == A[K])
            {
                for (L = K; L < (*T - 1); L++)
                {
                    A[L] = A[L + 1];
                }
                (*T)--;

            }
            else
            {
                K++;
            }
        }
        I++;
    }
}
