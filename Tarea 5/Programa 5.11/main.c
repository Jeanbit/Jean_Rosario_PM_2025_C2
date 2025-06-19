#include <stdio.h>



const int MAX = 100;


void Lectura(int[], int);
int Binaria(int[], int, int);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do {
        printf("Ingrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(VEC, TAM);

    printf("Ingrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Binaria(VEC, TAM, ELE);

    if (RES)
        printf("\nEl elemento se encuentra en la posicion: %d", RES + 1);

    else
        printf("\nEl elemento no se encuentra en el arreglo");


}


void Lectura(int A[], int T)
{
    for (int I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}


int Binaria(int A[], int T, int E)
{
    int IZQ = 0, DER = T - 1, CEN;
    int POS = -1;

    while (IZQ <= DER && POS == -1) {
        CEN = (IZQ + DER) / 2;

        if (E == A[CEN])
            POS = CEN;
        else if (E > A[CEN])
            IZQ = CEN + 1;
        else
            DER = CEN - 1;
    }

    return POS;
}
