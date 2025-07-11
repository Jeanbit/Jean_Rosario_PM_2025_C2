#include <stdio.h>
#include <string.h>



int main(void)
{
    char cad[50];
    int res;
    FILE *ar;

    if ((ar = fopen("arc.txt", "w")) != NULL)
    {
        printf("\nDesea ingresar una cadena de caracteres? Si-1 No-0: ");
        scanf("%d", &res);
        getchar();

        while (res)
        {
            printf("Ingrese la cadena: ");
            fgets(cad, sizeof(cad), stdin);


            size_t len = strlen(cad);
            if (len > 0 && cad[len - 1] == '\n')
            {
                cad[len - 1] = '\0';
            }

            fputs(cad, ar);

            printf("\nDesea ingresar otra cadena de caracteres? Si-1 No-0: ");
            scanf("%d", &res);
            getchar();

            if (res)
                fputs("\n", ar);
        }

        fclose(ar);
    }
    else
    {
        printf("No se puede abrir el archivo\n");
    }


}
