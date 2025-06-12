#include <stdio.h>
#include <stdlib.h>



int mad(int);

int main(void)
{
    int NUM, RES;
    printf("\nIngresa el numero: ");
    scanf("%d", &NUM);
    RES = mad(NUM);
    printf("\nEl mayor divisor de %d es: %d", NUM, RES);
    return 0;
}

int mad(int N1)
{
    int I = N1 / 2;
    while (N1 % I != 0)
    {
        I--;
    }
    return I;
}
