#include <stdio.h>
#include <string.h>
#include <ctype.h>


int cuentap(char *);

void main(void)
{
    int i;
    char fra[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, sizeof(fra), stdin);


    fra[strcspn(fra, "\n")] = '\0';

    i = cuentap(fra);
    printf("\nLa linea de texto tiene %d palabras", i);
}

int cuentap(char *cad)
{

    int i = 0;
    int en_palabra = 0;

    while (*cad)
    {
        if (isalpha(*cad))
        {
            if (!en_palabra)
            {
                en_palabra = 1;
                i++;
            }
        }
        else
        {
            en_palabra = 0;
        }
        cad++;
    }

    return i;
}
