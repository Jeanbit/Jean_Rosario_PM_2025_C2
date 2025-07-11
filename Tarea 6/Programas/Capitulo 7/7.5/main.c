#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i;
    double d;
    long l;
    char cad0[100], *resto;

    printf("\nIngrese una cadena de caracteres (entero): ");
    fgets(cad0, sizeof(cad0), stdin);
    cad0[strcspn(cad0, "\n")] = '\0';
    i = atoi(cad0);
    printf("\nCadena: %s\t Entero + 3: %d", cad0, i + 3);

    printf("\n\nIngrese una cadena de caracteres (real): ");
    fgets(cad0, sizeof(cad0), stdin);
    cad0[strcspn(cad0, "\n")] = '\0';

    d = atof(cad0);
    printf("\nCadena: %s\t Real + 1.5: %.2lf", cad0, d + 1.5);

    d = strtod(cad0, &resto);
    printf("\nstrtod: %.2lf\t Resto: %s", d + 1.5, resto);

    l = atol(cad0);
    printf("\n\natol: %ld\t +10: %ld", l, l + 10);

    l = strtol(cad0, &resto, 0);
    printf("\nstrtol: %ld\t Resto: %s\n", l + 10, resto);

    return 0;
}
