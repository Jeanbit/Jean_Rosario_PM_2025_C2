#include <stdio.h>
#include <stdlib.h>

int esPrimo(int num)
{
    if (num < 2)
        return 0;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int N1, N2;

    printf("Ingrese el primer numero entero positivo (N1): ");
    scanf("%d", &N1);
    printf("Ingrese el segundo numero entero positivo (N2): ");
    scanf("%d", &N2);


    if (N1 > N2)
    {
        int temp = N1;
        N1 = N2;
        N2 = temp;
    }

    printf("Pares de primos gemelos entre %d y %d:\n", N1, N2);

    for (int i = N1; i <= N2 - 2; i++)
    {
        if (esPrimo(i) && esPrimo(i + 2))
        {
            printf("(%d, %d)\n", i, i + 2);
        }
    }

    return 0;
}
