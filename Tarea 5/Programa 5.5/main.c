#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define RANGO 6

void Lectura(int *, int);
void Frecuencia(int *, int *, int, int);
void Impresion(int *, int);
void Mayor(int *, int);

int main(void)
{
    int CAL[TAM];
    int FRE[RANGO] = {0};
    Lectura(CAL, TAM);
    Frecuencia(CAL, FRE, TAM, RANGO);

    printf("\nFrecuencia de Calificaciones:\n");
    Impresion(FRE, RANGO);

    Mayor(FRE, RANGO);
    return 0;
}


void Lectura(int VEC[], int T)
{
    for (int i = 0; i < T; i++)
    {
        printf("Ingrese la calificacion (0-5) del alumno %d: ", i + 1);
        scanf("%d", &VEC[i]);
    }
}


void Impresion(int VEC[], int T)
{
    for (int i = 0; i < T; i++)
    {
        printf("VEC[%d]: %d\n", i, VEC[i]);
    }
}


void Frecuencia(int A[], int B[], int nAlumnos, int nCalificaciones)
{
    for (int i = 0; i < nAlumnos; i++)
    {
        if (A[i] >= 0 && A[i] < nCalificaciones)
        {
            B[A[i]]++;
        }
    }
}


void Mayor(int *x, int T)
{
    int i, MFRE = 0, WVAL = x[0];

    for (i = 1; i < T; i++)
    {
        if (x[i] > WVAL)
        {
            WVAL = x[i];
            MFRE = i;
        }
    }

    printf("\nMayor frecuencia de calificaciones: %d (Valor: %d)\n", MFRE, WVAL);
}
