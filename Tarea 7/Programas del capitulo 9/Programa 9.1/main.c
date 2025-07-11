#include <stdio.h>
#include <stdlib.h>

void  main(void)
{
    char p1;
    FILE *ar;
    ar = fopen("c:\\Users\Public\\arc.txt","w");
    if (ar != NULL)

    {
        printf("Escribir lo que quieres en el archivo: ");

        while ((p1 = getchar()) != '\n')
        {
            fputc(p1,ar);
        }

        fclose(ar);
    }
    else
        printf("No se puede abrir el archivo");

}
