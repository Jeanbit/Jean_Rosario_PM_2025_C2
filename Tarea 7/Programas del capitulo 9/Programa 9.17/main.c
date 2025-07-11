#include <stdio.h>
#include <ctype.h>
#include <string.h>


void cambia(FILE *, FILE *);

int main(void)
{
    FILE *ar;
    FILE *ap;


    ar = fopen("arc.txt", "r");
    ap = fopen("arc1.txt", "w");

    if (ar != NULL && ap != NULL)
    {
        cambia(ar, ap);
        fclose(ar);
        fclose(ap);
    }
    else
    {
        printf("No se pueden abrir los archivos.\n");
    }

    return 0;
}

void cambia(FILE *ap1, FILE *ap2)
{
    char cad[1024];
    char *cad1, *cad2;


    while (fgets(cad, sizeof(cad), ap1) != NULL)
    {
        cad1 = cad;


        while ((cad2 = strstr(cad1, "mexico")) != NULL)
        {

            cad2[0] = 'M';


            cad1 = cad2 + 1;
        }


        fputs(cad, ap2);
    }
}
