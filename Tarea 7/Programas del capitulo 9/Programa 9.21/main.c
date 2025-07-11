#include <stdio.h>

typedef struct
{
    int clave;
    char nombre[20];
    int carrera;
    float promedio;
    float examen;
    char telefono[12];
} alumno;

float F1(FILE *);
void F2(FILE *, FILE *, FILE *, FILE *, FILE *, FILE *);
void F3(FILE *, FILE *, FILE *, FILE *, FILE *);

int main(void)
{
    float pro;
    FILE *ap, *c1, *c2, *c3, *c4, *c5;

    ap = fopen("alu1.dat", "rb");
    c1 = fopen("car1.dat", "w+b");
    c2 = fopen("car2.dat", "w+b");
    c3 = fopen("car3.dat", "w+b");
    c4 = fopen("car4.dat", "w+b");
    c5 = fopen("car5.dat", "w+b");

    if ((ap != NULL) && (c1 != NULL) && (c2 != NULL) && (c3 != NULL) &&
            (c4 != NULL) && (c5 != NULL))
    {

        pro = F1(ap);
        printf("\nPromedio de examen de admision: %.2f", pro);

        F2(ap, c1, c2, c3, c4, c5);
        F3(c1, c2, c3, c4, c5);

        fclose(ap);
        fclose(c1);
        fclose(c2);
        fclose(c3);
        fclose(c4);
        fclose(c5);
    }
    else
    {
        printf("\nEl o los archivos no se pudieron abrir");
    }

    return 0;
}

float F1(FILE *ap)
{
    alumno alu;
    float sum = 0, pro;
    int i = 0;

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {
        sum += alu.examen;
        i++;
    }

    if (i == 0)
        return 0.0;

    return sum / i;
}

void F2(FILE *ap, FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    alumno alu;
    rewind(ap);

    while (fread(&alu, sizeof(alumno), 1, ap) == 1)
    {

        if (((alu.examen >= 1300) && (alu.promedio >= 8)) || ((alu.examen >= 1400) && (alu.promedio >= 7)))
        {
            switch (alu.carrera)
            {
            case 1:
                fwrite(&alu, sizeof(alumno), 1, c1);
                break;
            case 2:
                fwrite(&alu, sizeof(alumno), 1, c2);
                break;
            case 3:
                fwrite(&alu, sizeof(alumno), 1, c3);
                break;
            case 4:
                fwrite(&alu, sizeof(alumno), 1, c4);
                break;
            case 5:
                fwrite(&alu, sizeof(alumno), 1, c5);
                break;
            }
        }
    }
}

void F3(FILE *c1, FILE *c2, FILE *c3, FILE *c4, FILE *c5)
{
    FILE *carreras[5] = {c1, c2, c3, c4, c5};
    alumno alu;
    float cal[5] = {0};
    int i, count;

    for (i = 0; i < 5; i++)
    {
        rewind(carreras[i]);
        float sum = 0;
        count = 0;

        while (fread(&alu, sizeof(alumno), 1, carreras[i]) == 1)
        {
            sum += alu.examen;
            count++;
        }

        if (count != 0)
            cal[i] = sum / count;
        else
            cal[i] = 0;

        printf("\nPromedio carrera %d: %.2f", i + 1, cal[i]);
    }
}
