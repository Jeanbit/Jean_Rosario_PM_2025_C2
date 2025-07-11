#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void lee(FILE *);

int main(void)
{
    FILE *ar;
    if ((ar = fopen("ad1.dat", "rb")) != NULL)
    {
        lee(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir.\n");
    }

    return 0;
}

void lee(FILE *ap)

{
    alumno alu;


    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        printf("\nMatricula: %d", alu.matricula);
        printf("\tCarrera: %d", alu.carrera);
        printf("\tPromedio: %.2f\t", alu.promedio);
        printf("Nombre: %s\n", alu.nombre);
    }
}
