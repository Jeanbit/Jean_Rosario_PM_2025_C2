#include <stdio.h>
#include <string.h>

void inverso(char *);

void main(void)
{
    char fra[50];
    printf("\nIngrese la linea de texto: ");
    fgets(fra, sizeof(fra), stdin);
    fra[strcspn(fra, "\n")] = '\0';
    printf("\nEscribe la linea de texto en forma inversa: ");
    inverso(fra);
}

void inverso(char *cadena)

{
    if (cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
