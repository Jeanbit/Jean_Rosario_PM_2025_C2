#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Par, impar o nulo.
NUM: variable de tipo entero. */

void main(void)
{
    int NUM;
    printf("Ingree el numero: ");
    scanf("%d", &NUM);
    if (NUM == 0)
        printf("\nNulo");

    else if (pow (-1, NUM) > 0)
        printf("\nPar");
    else
        printf("\nImpar");

}
