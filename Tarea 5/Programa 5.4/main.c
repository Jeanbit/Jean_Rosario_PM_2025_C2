#include <stdio.h>

const int MAX = 10;

void Lectura(int VEC[], int T);
void Imprime(int VEC[], int T);
void Producto(int *X, int *Y, int *Z, int T);

int main(void)
{
    int VE1[MAX], VE2[MAX], VE3[MAX];


    Lectura(VE1, MAX);
    Lectura(VE2, MAX);


    Producto(VE1, VE2, VE3, MAX);


    printf("\nProducto de los Vectores\n");
    Imprime(VE3, MAX);

    return 0;
}

void Lectura(int VEC[], int T)
{
    int i;
    printf("\nLectura de vector:\n");
    for (i = 0; i < T; i++)
    {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &VEC[i]);
    }
}

void Imprime(int VEC[], int T)
{
    int i;
    for (i = 0; i < T; i++)
    {
        printf("VEC[%d]: %d\n", i + 1, VEC[i]);
    }
}

void Producto(int *X, int *Y, int *Z, int T)
{
    int i;
    for (i = 0; i < T; i++)
    {
        Z[i] = X[i] * Y[i];
    }
}
