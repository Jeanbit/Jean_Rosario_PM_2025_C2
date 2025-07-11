#include <stdio.h>


typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void modifica(FILE *);

int main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "r+b")) != NULL)
    {
        modifica(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir.\n");
    }

    return 0;
}

void modifica(FILE *ap)
{
    int d;
    alumno alu;

    printf("\nIngrese el numero de registro que desea modificar (comenzando en 1): ");
    scanf("%d", &d);


    if (fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET) != 0)
    {
        printf("Error al posicionar el puntero.\n");
        return;
    }


    if (fread(&alu, sizeof(alumno), 1, ap) != 1)
    {
        printf("Error al leer el registro.\n");
        return;
    }


    printf("\nDatos actuales del alumno:\n");
    printf("Matricula: %d\n", alu.matricula);
    printf("Nombre: %s\n", alu.nombre);
    printf("Carrera: %d\n", alu.carrera);
    printf("Promedio actual: %.2f\n", alu.promedio);


    printf("\nIngrese el promedio correcto del alumno: ");
    scanf("%f", &alu.promedio);


    fseek(ap, (d - 1) * sizeof(alumno), SEEK_SET);


    if (fwrite(&alu, sizeof(alumno), 1, ap) != 1)
    {
        printf("Error al escribir el nuevo promedio.\n");
    }
    else
    {
        printf("Promedio actualizado exitosamente.\n");
    }
}
