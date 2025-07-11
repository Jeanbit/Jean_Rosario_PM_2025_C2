#include <stdio.h>

int main(void)
{
    char p1;
    FILE *ar;

    ar = fopen("libro.txt", "a");

    if (ar != NULL)
    {
        printf("Escribe una linea de texto (termina con ENTER):\n");
        while ((p1 = getchar()) != '\n')
        {
            fputc(p1, ar);
        }

        fclose(ar);
        printf("Texto agregado exitosamente al archivo.\n");
    }
    else
    {
        printf("No se puede abrir el archivo.\n");
    }


}
