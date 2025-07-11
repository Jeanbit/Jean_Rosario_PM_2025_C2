#include <stdio.h>


void Lectura1(int [15][12]);
void Lectura2(float[], int);
void Funcion1(int [][12], int, int, float[], float[]);
void Funcion2(float[], int);
void Funcion3(float[], int);

int main(void)
{
    int FAB[15][12] = {0};
    float COS[15], VEN[15];

    Lectura1(FAB);
    Lectura2(COS, 15);
    Funcion1(FAB, 15, 12, COS, VEN);
    Funcion2(VEN, 15);
    Funcion3(VEN, 15);

    return 0;
}

void Lectura1(int A[][12])
{
    int MES, PRO, CAN;
    printf("\nIngrese mes, tipo de producto y cantidad vendida (-1 -1 -1 para terminar): ");
    scanf("%d %d %d", &MES, &PRO, &CAN);

    while (MES != -1 && PRO != -1 && CAN != -1)
    {
        A[PRO - 1][MES - 1] += CAN;
        printf("Ingrese mes, tipo de producto y cantidad vendida: ");
        scanf("%d %d %d", &MES, &PRO, &CAN);
    }
}

void Lectura2(float A[], int N)
{
    int I;
    for (I = 0; I < N; I++)
    {
        printf("Ingrese costo del producto %d: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void Funcion1(int A[][12], int F, int C, float V1[], float V2[])
{
    int I, J, SUM;
    printf("\n");
    for (I = 0; I < F; I++)
    {
        SUM = 0;
        for (J = 0; J < C; J++)
            SUM += A[I][J];
        V2[I] = V1[I] * SUM;
        printf("Total de ventas del producto %d: %8.2f\n", I + 1, V2[I]);
    }
}

void Funcion2(float A[], int C)
{
    int I;
    float SUM = 0;
    for (I = 0; I < C; I++)
        SUM += A[I];

    printf("\nMonto total de ventas de la f�brica: %.2f\n", SUM);
}

void Funcion3(float A[], int C)
{
    int I, MAXPOS = 0;
    float MAX = A[0];

    for (I = 1; I < C; I++)
    {
        if (A[I] > MAX)
        {
            MAX = A[I];
            MAXPOS = I;
        }
    }

    printf("Producto mas vendido: %d con ventas de %.2f\n", MAXPOS + 1, MAX);
}
