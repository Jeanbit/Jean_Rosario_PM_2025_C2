#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cad[50];
    FILE *ap;
    if ((ap = fopen ("arc.txt", "r"))!= NULL)
    {
        while (!feof(ap))
        {
            fgets(cad, 50, ap);
            puts(cad);
        }
        fclose(ap);
    }
    else
        printf("No se puede abrir el archivo");

}
