#include <stdio.h>

typedef struct
{
    char materia[20];
    int calificacion;
} matcal;

typedef struct
{
    int matricula;
    char nombre[20];
    matcal cal[5];
} alumno;

void F1(FILE *);
void F2(FILE *);
float F3(FILE *);

int main(void)
{
    float pro;
    FILE *ap;

    if ((ap = fopen("esc.dat", "rb")) != NULL)
    {
        F1(ap);
        F2(ap);
        pro = F3(ap);
        printf("\n\nPromedio general de la materia 4: %.2f", pro);
        fclose(ap);
    }
    else
        printf("\nEl archivo no se puede abrir");

    return 0;
}

void F1(FILE *ap)

{
    alumno alu;
    int j;
    float sum, pro;

    printf("\nMatricula y promedios");
    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        printf("\nMatricula: %d", alu.matricula);
        sum = 0.0;
        for (j = 0; j < 5; j++)
            sum += alu.cal[j].calificacion;
        pro = sum / 5;
        printf("\tPromedio: %.2f", pro);
    }
}

void F2(FILE *ap)

{
    alumno alu;
    rewind(ap);
    printf("\n\nAlumnos con calificacion > 9 en materia 3");

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        if (alu.cal[2].calificacion > 9)
            printf("\nMatricula del alumno: %d", alu.matricula);
    }
}

float F3(FILE *ap)

{
    alumno alu;
    int i = 0;
    float sum = 0.0;

    rewind(ap);
    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        sum += alu.cal[3].calificacion;
        i++;
    }

    if (i == 0) return 0.0;
    return sum / i;
}
