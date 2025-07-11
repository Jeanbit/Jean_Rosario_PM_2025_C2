#include <stdio.h>


typedef struct
{
    int clave;
    int departamento;
    float salario;
    float ventas[12];
} empleado;

void incrementa(FILE *);

int main(void)
{
    FILE *ar;

    if ((ar = fopen("ad5.dat", "r+b")) != NULL)
    {
        incrementa(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir.\n");
    }

    return 0;
}

void incrementa(FILE *ap)
{
    empleado emple;
    int i = 0;
    float sum;


    while (fread(&emple, sizeof(empleado), 1, ap) == 1)
    {
        sum = 0.0;
        for (int j = 0; j < 12; j++)
        {
            sum += emple.ventas[j];
        }

        if (sum > 1000000.0)
        {
            emple.salario *= 1.10;


            fseek(ap, -sizeof(empleado), SEEK_CUR);
            fwrite(&emple, sizeof(empleado), 1, ap);


            fflush(ap);
        }
    }
}
