#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int NUM;

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &NUM);

    if (NUM <= 2) {
        printf("No hay numeros primos menores que %d.\n", NUM);
        return 0;
    }

    printf("Numeros primos menores que %d:\n", NUM);

    for (int i = 2; i < NUM; i++) {
        int esPrimo = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                esPrimo = 0;
                break;
            }
        }
        if (esPrimo)
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}
