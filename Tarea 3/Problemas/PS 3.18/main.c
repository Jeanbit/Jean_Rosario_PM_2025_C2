#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int limite = N - i;

        for (int j = 1; j <= limite; j++)
        {
            printf("%d ", j);
        }

        for (int k = 0; k < i * 2; k++)
        {
            printf("  ");
        }

        for (int j = limite; j >= 1; j--)
        {
            printf("%d ", j);
        }

        printf("\n");
    }

    return 0;
}
