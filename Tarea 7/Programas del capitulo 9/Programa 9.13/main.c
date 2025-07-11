#include <stdio.h>


int cuenta(char car);

int main(void)
{
    int res;
    char car;

    printf("\nIngrese el caracter que se va a buscar en el archivo: ");
    car = getchar();


    while (getchar() != '\n');

    res = cuenta(car);

    if (res != -1)
        printf("\n\nEl caracter '%c' se encuentra en el archivo %d veces.\n", car, res);
    else
        printf("\nNo se pudo abrir el archivo.\n");

    return 0;
}

int cuenta(char car)
{
    int con = 0;
    char p;
    FILE *ar;

    ar = fopen("arc.txt", "r");

    if (ar != NULL)
    {
        while ((p = getc(ar)) != EOF)
        {
            if (p == car)
                con++;
        }
        fclose(ar);
        return con;
    }
    else
    {
        return -1;
    }
}
