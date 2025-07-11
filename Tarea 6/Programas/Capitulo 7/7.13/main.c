#include <stdio.h>
#include <string.h>

int cuenta(char *);

int main(void)
{
    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);


    cad[strcspn(cad, "\n")] = '\0';

    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d", i);

    return 0;
}

int cuenta(char *cadena)
{
    int c = 0;

    while (cadena[c] != '\0')
        c++;
    return c;
}
