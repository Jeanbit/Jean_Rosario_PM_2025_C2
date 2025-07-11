#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char c;
    char cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();
    getchar(); //

    while (c == 'S' || c == 's')
    {
        printf("\nIngrese la cadena de caracteres: ");
        fgets(cad, sizeof(cad), stdin);
        cad[strcspn(cad, "\n")] = '\0';

        i++;
        sum += atof(cad);

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
        getchar();
    }

    if (i > 0)
    {
        printf("\nSuma: %.2f", sum);
        printf("\nPromedio: %.2f\n", sum / i);
    }
    else
    {
        printf("\nNo se ingresaron datos validos.\n");
    }

    return 0;
}
