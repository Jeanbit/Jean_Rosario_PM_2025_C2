#include <stdio.h>
#define MAX 100


void Lectura(int A[], int T);
int Busca(int A[], int T, int K);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];


    do {
        printf("Ingrese el tamano del arreglo (1-100): ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);


    Lectura(VEC, TAM);


    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);


    RES = Busca(VEC, TAM, ELE);


    if (RES)
        printf("\nEl elemento se encuentra en la posicion %d.\n", RES);
    else
        printf("\nEl elemento no se encuentra en el arreglo.\n");


}


void Lectura(int A[], int T)
{
    for (int I = 0; I < T; I++) {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}


int Busca(int A[], int T, int K)
{
    int I = 0;
    while (I < T) {
        if (A[I] == K)
            return I + 1;
        I++;
    }

}
