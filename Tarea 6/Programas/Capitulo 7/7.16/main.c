#include <stdio.h>
#include <string.h>

void main(void)
{
    char cad1[50], cad2[50];
    int i = 0;
    char *cad0;

    printf("\nIngrese la primera cadena de caracteres: ");
    fgets(cad1, sizeof(cad1), stdin);
    cad1[strcspn(cad1, "\n")] = '\0';

    printf("\nIngrese la cadena a buscar: ");
    fgets(cad2, sizeof(cad2), stdin);
    cad2[strcspn(cad2, "\n")] = '\0';

    cad0 = cad1;

    while ((cad0 = strstr(cad0, cad2)) != NULL)
    {
        i++;
        cad0++;
    }

    printf("\nEl numero de veces que aparece la segunda cadena es: %d\n", i);
}
