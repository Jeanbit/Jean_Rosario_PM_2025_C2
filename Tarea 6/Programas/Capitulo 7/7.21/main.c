#include <stdio.h>
#include <string.h>

void intercambia(char FRA[][30], int n);
void main(void)
{
    int i, n;
    char FRA[20][30];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);


    getchar();

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea de texto n�mero %d: ", i + 1);
        fgets(FRA[i], sizeof(FRA[i]), stdin);
        FRA[i][strcspn(FRA[i], "\n")] = '\0';
    }

    printf("\n\n");
    intercambia(FRA, n);

    for (i = 0; i < n; i++)
    {
        printf("Impresi�n de la linea de texto %d: ", i + 1);
        puts(FRA[i]);
    }
}

void intercambia(char FRA[][30], int n)
{
    int i, j;
    j = n - 1;
    char cad[30];


    for (i = 0; i < (n / 2); i++)
    {
        strcpy(cad, FRA[i]);
        strcpy(FRA[i], FRA[j]);
        strcpy(FRA[j], cad);
        j--;
    }
}
