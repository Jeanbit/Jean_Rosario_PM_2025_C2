#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int edad;
    float promedio;
} Alumno;


void guardarAlumnos(Alumno *alumnos, int n)
{
    FILE *f = fopen("alumnos.dat", "wb");
    if (!f)
    {
        printf("No se pudo abrir el archivo para escribir.\n");
        return;
    }
    fwrite(&n, sizeof(int), 1, f);
    fwrite(alumnos, sizeof(Alumno), n, f);
    fclose(f);
}


Alumno* leerAlumnos(int *n)
{
    FILE *f = fopen("alumnos.dat", "rb");
    if (!f)
    {
        printf("No se pudo abrir el archivo para leer.\n");
        return NULL;
    }

    fread(n, sizeof(int), 1, f);
    Alumno *alumnos = (Alumno *)malloc(*n * sizeof(Alumno));
    if (!alumnos)
    {
        printf("No se pudo asignar memoria.\n");
        fclose(f);
        return NULL;
    }

    fread(alumnos, sizeof(Alumno), *n, f);
    fclose(f);
    return alumnos;
}


void ordenarPorNombre(Alumno *alumnos, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0)
            {
                Alumno temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}


void ordenarPorPromedio(Alumno *alumnos, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (alumnos[j].promedio < alumnos[j + 1].promedio)
            {
                Alumno temp = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = temp;
            }
        }
    }
}


void imprimirAlumnos(Alumno *alumnos, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nAlumno %d:\n", i + 1);
        printf("Nombre: %s\n", alumnos[i].nombre);
        printf("Edad: %d\n", alumnos[i].edad);
        printf("Promedio: %.2f\n", alumnos[i].promedio);
    }
}

int main()
{
    int n, opcion;
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    Alumno *alumnos = (Alumno *)malloc(n * sizeof(Alumno));
    if (!alumnos)
    {
        printf("No se pudo asignar memoria.\n");
        return 1;
    }


    for (int i = 0; i < n; i++)
    {
        printf("\n--- Alumno %d ---\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", alumnos[i].nombre);
        printf("Edad: ");
        scanf("%d", &alumnos[i].edad);
        printf("Promedio: ");
        scanf("%f", &alumnos[i].promedio);
    }


    guardarAlumnos(alumnos, n);
    free(alumnos);


    Alumno *leidos = leerAlumnos(&n);
    if (!leidos) return 1;


    printf("\n¿Cómo desea ordenar los alumnos?\n");
    printf("1. Por nombre (A-Z)\n");
    printf("2. Por promedio (mayor a menor)\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion == 1)
    {
        ordenarPorNombre(leidos, n);
    }
    else if (opcion == 2)
    {
        ordenarPorPromedio(leidos, n);
    }
    else
    {
        printf("Opción inválida.\n");
        free(leidos);
        return 1;
    }


    printf("\n--- Alumnos Ordenados ---\n");
    imprimirAlumnos(leidos, n);

    free(leidos);

}
