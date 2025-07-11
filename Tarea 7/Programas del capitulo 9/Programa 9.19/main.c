#include <stdio.h>

typedef struct
{
    int matricula;
    char nombre[20];
    int carrera;
    float promedio;
} alumno;

void ordena(FILE *ap1, FILE *ap2)

{
    alumno alu, alu2;
    int t, n, i, j;
    t = sizeof(alumno);

    fseek(ap1, 0, SEEK_END);
    n = ftell(ap1) / t;
    rewind(ap1);


    for (i = 0; i < n - 1; i++)
    {
        rewind(ap1);

        for (j = 0; j < n - i - 1; j++)
        {
            fread(&alu, sizeof(alumno), 1, ap1);
            fread(&alu2, sizeof(alumno), 1, ap1);

            if (alu.matricula > alu2.matricula)
            {

                fseek(ap1, -2 * sizeof(alumno), SEEK_CUR);
                fwrite(&alu2, sizeof(alumno), 1, ap2);
                fwrite(&alu, sizeof(alumno), 1, ap2);

                fseek(ap1, sizeof(alumno), SEEK_CUR);
            }
            else
            {

                fwrite(&alu, sizeof(alumno), 1, ap2);
                fseek(ap1, sizeof(alumno), SEEK_CUR);
            }
        }
    }
}
