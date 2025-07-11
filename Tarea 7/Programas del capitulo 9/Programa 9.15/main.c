#include <stdio.h>
#include <ctype.h>



void minymay(FILE *);

int main(void)
{
    FILE *ap;

    if ((ap = fopen("arc.txt", "r")) != NULL)
    {
        minymay(ap);
        fclose(ap);
    }
    else
    {
        printf("No se puede abrir el archivo.\n");
    }

    return 0;
}

void minymay(FILE *ap1)
{
    char cad[30];
    int i, mi = 0, ma = 0;


    while (fgets(cad, sizeof(cad), ap1) != NULL)
    {
        i = 0;
        while (cad[i] != '\0')
        {
            if (islower(cad[i]))
            {
                mi++;
            }
            else if (isupper(cad[i]))
            {
                ma++;
            }
            i++;
        }
    }

    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d\n", ma);
}
