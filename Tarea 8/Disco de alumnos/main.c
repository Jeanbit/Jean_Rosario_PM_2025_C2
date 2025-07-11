#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Alumno
{
    char nombre[50];
    int edad;
    float promedio;
    struct Alumno *siguiente;
} Alumno;


Alumno* crearAlumno()
{
    Alumno* nuevo = (Alumno*)malloc(sizeof(Alumno));
    if (nuevo == NULL)
    {
        printf("No se pudo asignar memoria.\n");
        exit(1);
    }
    nuevo->siguiente = NULL;
    return nuevo;
}


void guardarEnArchivo(Alumno *inicio)
{
    FILE *archivo = fopen("alumnos.dat", "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir archivo.\n");
        return;
    }

    Alumno *actual = inicio;
    while (actual != NULL)
    {
        fwrite(actual, sizeof(Alumno) - sizeof(Alumno*), 1, archivo);
        actual = actual->siguiente;
    }

    fclose(archivo);
}


Alumno* leerDesdeArchivo()
{
    FILE *archivo = fopen("alumnos.dat", "rb");
    if (archivo == NULL)
    {
        printf("No se pudo abrir archivo.\n");
        return NULL;
    }

    Alumno *inicio = NULL, *fin = NULL;
    while (1)
    {
        Alumno *nuevo = crearAlumno();
        if (fread(nuevo, sizeof(Alumno) - sizeof(Alumno*), 1, archivo) != 1)
        {
            free(nuevo);
            break;
        }

        if (inicio == NULL)
        {
            inicio = nuevo;
            fin = nuevo;
        }
        else
        {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }

    fclose(archivo);
    return inicio;
}


void mostrarAlumnos(Alumno *inicio)
{
    Alumno *actual = inicio;
    int i = 1;
    while (actual != NULL)
    {
        printf("\nAlumno %d\n", i++);
        printf("Nombre: %s\n", actual->nombre);
        printf("Edad: %d\n", actual->edad);
        printf("Promedio: %.2f\n", actual->promedio);
        actual = actual->siguiente;
    }
}


void liberarLista(Alumno *inicio)
{
    Alumno *actual;
    while (inicio != NULL)
    {
        actual = inicio;
        inicio = inicio->siguiente;
        free(actual);
    }
}

int main()
{
    int n, i;
    Alumno *inicio = NULL, *fin = NULL;

    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        Alumno *nuevo = crearAlumno();

        printf("\n--- Alumno %d ---\n", i + 1);
        printf("Nombre: ");
        scanf(" %[^\n]", nuevo->nombre);
        printf("Edad: ");
        scanf("%d", &nuevo->edad);
        printf("Promedio: ");
        scanf("%f", &nuevo->promedio);

        if (inicio == NULL)
        {
            inicio = nuevo;
            fin = nuevo;
        }
        else
        {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }

    guardarEnArchivo(inicio);
    liberarLista(inicio);

    printf("\nLeyendo desde archivo:\n");
    Alumno *leidos = leerDesdeArchivo();
    mostrarAlumnos(leidos);
    liberarLista(leidos);

    return 0;
}
