#include <stdio.h>
#include <stdlib.h>

int main()
{
int edad;
// hacer un programa que determine el rango de edad de una perssona
// 1- recien nacido persona de edad  menoral ano
// 2- infante con edad entre 1 y  3 anos
// 3- nino con  edad  entre 3  y 12
// 4- adolecente con edad mayor 12 anos y menor 18
// 5- Mayor de  edad es una  persona mayor de 18 y  menor 38
// 6- Adulto mayor es mayor  de 38 y  menor de  68
// 7- Envejeciente mayor de 68 y   menor de 86
// 8- Anciano es mayor  de 86 anos
    printf("Clase de Seleccion!\n");
    printf ("Ingrese u edad: ");
    scanf("%i",&edad);
    if( edad >= 0 && edad <= 120)

    {
        if(edad < 1)
        {
            printf("Recien nacido\n");
        }

        else if(edad >=1 && edad < 3)
        {
            printf("Infante\n");
        }
        else if(edad >=3 && edad <12)
        {
            printf("nino\n");
        }
        else if (edad >=12 && edad <18)
        {
            printf("Adolecente\n");
        }
        else if (edad >=18 && edad <38)
        {
            printf("Mayor de edad\n");
        }
        else if(edad >=38 && edad <68)

        {
            printf("Adulto mayor\n");
        }
        else if(edad >=68 && edad <86)
        {
            printf("Envejeciente\n");
        }
        else if (edad >=86)
        {
            printf("Anciano\n");
        }
        return 0;
    }
}
