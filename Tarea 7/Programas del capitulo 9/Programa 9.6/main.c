#include <stdio.h>



int main(void)
{
    int i, j, n, mat;
    float cal, pro;
    FILE *ar;

    if ((ar = fopen("arc9.txt", "r")) != NULL)
    {
        fscanf(ar, "%d", &n);
        for (i = 0; i < n; i++)
        {
            fscanf(ar, "%d", &mat);
            pro = 0;

            for (j = 0; j < 5; j++)
            {
                fscanf(ar, "%f", &cal);
                pro += cal;
            }

            printf("Matricula: %d\t Promedio: %.2f\n", mat, pro / 5);
        }

        fclose(ar);
    }
    else {
        printf("No se puede abrir el archivo.\n");
    }


}
