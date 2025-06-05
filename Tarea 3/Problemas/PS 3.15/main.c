#include <stdio.h>
#include <stdlib.h>

int main() {
    int N1, N2, temp;

    printf("Ingrese el primer numero (N1): ");
    scanf("%d", &N1);

    printf("Ingrese el segundo numero (N2): ");
    scanf("%d", &N2);

    if (N1 <= 0 || N2 <= 0) {
        printf("Ambos numeros deben ser naturales (mayores que cero).\n");
        return 1;
    }

    while (N2 != 0) {
        temp = N2;
        N2 = N1 % N2;
        N1 = temp;
    }

    printf("El MCD es: %d\n", N1);
    return 0;
}
