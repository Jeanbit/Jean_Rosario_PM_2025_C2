#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado
{
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion;
};

void Lectura(struct empleado *a)
{

    printf("\nIngrese el nombre del empleado: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0';
    printf("Ingrese el departamento de la empresa: ");
    fgets(a->departamento, sizeof(a->departamento), stdin);
    a->departamento[strcspn(a->departamento, "\n")] = '\0';

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    fflush(stdin);

    printf(" Ingrese la dirección del empleado ");
    printf("\n\tCalle: ");
    fgets(a->direccion.calle, sizeof(a->direccion.calle), stdin);
    a->direccion.calle[strcspn(a->direccion.calle, "\n")] = '\0';

    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    printf("\tCodigo Postal: ");
    scanf("%d", &a->direccion.cp);
    fflush(stdin);

    printf("\tLocalidad: ");
    fgets(a->direccion.localidad, sizeof(a->direccion.localidad), stdin);
    a->direccion.localidad[strcspn(a->direccion.localidad, "\n")] = '\0';

    void main(void)
    {
        struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jeronimo", 120, 3490, "Toluca"}};
        struct empleado *e1, *e2, e3, e4;


        e1 = (struct empleado *)malloc(sizeof(struct empleado));
        if (e1 == NULL)
        {
            printf("Error en la asignacion de memoria para e1\n");
            return;
        }

        printf("\nIngrese el nombre del empleado 1: ");
        scanf("%s", e1->nombre);
        fflush(stdin);

        printf("Ingrese el departamento de la empresa: ");
        fgets(e1->departamento, sizeof(e1->departamento), stdin);
        e1->departamento[strcspn(e1->departamento, "\n")] = '\0';
        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &e1->sueldo);

        printf(" Ingrese la direccion del empleado ");
        printf("\n\tCalle: ");
        fflush(stdin);
        fgets(e1->direccion.calle, sizeof(e1->direccion.calle), stdin);
        e1->direccion.calle[strcspn(e1->direccion.calle, "\n")] = '\0';
        printf("\tNumero: ");
        scanf("%d", &e1->direccion.numero);
        printf("\tCodigo Postal: ");
        scanf("%d", &e1->direccion.cp);
        printf("\tLocalidad: ");
        fflush(stdin);
        fgets(e1->direccion.localidad, sizeof(e1->direccion.localidad), stdin);
        e1->direccion.localidad[strcspn(e1->direccion.localidad, "\n")] = '\0';
        printf("\nIngrese el nombre del empleado 3: ");
        scanf("%s", e3.nombre);
        fflush(stdin);
        printf("Ingrese el departamento de la empresa: ");
        fgets(e3.departamento, sizeof(e3.departamento), stdin);
        e3.departamento[strcspn(e3.departamento, "\n")] = '\0';
        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &e3.sueldo);

        printf(" Ingrese la direccion del empleado ");
        printf("\n\tCalle: ");
        fflush(stdin);
        fgets(e3.direccion.calle, sizeof(e3.direccion.calle), stdin);
        e3.direccion.calle[strcspn(e3.direccion.calle, "\n")] = '\0';

        printf("\tNumero: ");
        scanf("%d", &e3.direccion.numero);
        printf("\tCodigo Postal: ");
        scanf("%d", &e3.direccion.cp);
        printf("\tLocalidad: ");
        fflush(stdin);
        fgets(e3.direccion.localidad, sizeof(e3.direccion.localidad), stdin);
        e3.direccion.localidad[strcspn(e3.direccion.localidad, "\n")] = '\0';

        e2 = (struct empleado *)malloc(sizeof(struct empleado));
        if (e2 == NULL)
        {
            printf("Error en la asignacion de memoria para e2\n");
            return;
        }

        Lectura(e2);
        Lectura(&e4);

        printf("\nDatos del empleado 1\n");
        printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e1->nombre, e1->departamento, e1->sueldo,
               e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

        printf("\nDatos del empleado 4\n");
        printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e4.nombre, e4.departamento, e4.sueldo,
               e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

        free(e1);
        free(e2);

    }
}
