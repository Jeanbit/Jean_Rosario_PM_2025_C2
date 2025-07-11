#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void escribe(FILE *);

int main(void)
{
    FILE *ar;

    if ((ar = fopen("ad1.dat", "wb")) != NULL)
    {
        escribe(ar);
        fclose(ar);
    }
    else
    {
        printf("\nEl archivo no se puede abrir.\n");
    }

    return 0;
}

void escribe(FILE *ap)
{
    alumno alu;
    int i = 0, r;

    printf("\nDesea ingresar informacion sobre alumnos? (Si-1 No-0): ");
    scanf("%d", &r);
    getchar();

    while (r)
    {
        i++;
        printf("\n--- Alumno %d ---\n", i);

        printf("Matricula: ");
        scanf("%d", &alu.matricula);
        getchar();
        printf("Nombre: ");
        fgets(alu.nombre, sizeof(alu.nombre), stdin);

        size_t len = strlen(alu.nombre);
        if (len > 0 && alu.nombre[len - 1] == '\n')
        {
            alu.nombre[len - 1] = '\0';
        }

        printf("Carrera (numero): ");
        scanf("%d", &alu.carrera);

        printf("Promedio: ");
        scanf("%f", &alu.promedio);
        getchar();


        fwrite(&alu, sizeof(alumno), 1, ap);

        printf("\nDesea ingresar informacion sobre mas alumnos? (Si-1 No-0): ");
        scanf("%d", &r);
        getchar();
    }
}
