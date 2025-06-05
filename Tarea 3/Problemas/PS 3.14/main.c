#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double factorial(int n) {
    double fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    double x, termino, senx = 0.0;
    int signo = 1, n = 1, contador = 0;

    printf("Ingrese el valor de X en radianes: ");
    scanf("%lf", &x);

    do {
        termino = signo * pow(x, n) / factorial(n);
        senx += termino;
        signo *= -1;
        n += 2;
        contador++;
    } while (fabs(termino) > 0.001);

    printf("\nEl valor de sen(%.4lf) ≈ %.5lf", x, senx);
    printf("\nNumero de terminos utilizados: %d\n", contador);

    return 0;
}
