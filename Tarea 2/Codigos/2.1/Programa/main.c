#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Promedio curso.
El programa, al recibir como dato el promedio de
un alumno en un curso universitario, esscribe aprobado
si su promedio es mayor o igual a 6

PRO: variable tipo real. */

void main(void)
{
float PRO;
printf("Ingrese el promedio del alumno: ");
scanf("%f", &PRO);
if (PRO >= 6)
    printf("\nAprobado");

}
