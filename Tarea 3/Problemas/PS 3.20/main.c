#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int T, P, R;
    long resultado;

    printf("Valores positivos de T, P y R que cumplen: 7*T^4 - 6*P^3 + 12*R^5 < 5850\n\n");

    for (T = 1; T <= 10; T++)
    {
        for (P = 1; P <= 20; P++)
        {
            for (R = 1; R <= 5; R++)
            {
                resultado = 7 * pow(T, 4) - 6 * pow(P, 3) + 12 * pow(R, 5);
                if (resultado < 5850)
                {
                    printf("T = %d, P = %d, R = %d Resultado = %ld\n", T, P, R, resultado);
                }
            }
        }
    }

    return 0;
}
