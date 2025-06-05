#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I = 0;
    float SAL = 0.0, NOM = 0.0;
    float SALimp = 0.0, SalMenosImp = 0.0;

    for(I = 1; I <= 5; I++)

    {
       printf("\nIngrese el salario del profesor %d:\t", I);
       scanf("%f",&SAL);
       SALimp = SAL * 0.12;
       SalMenosImp = SAL - SALimp;
       printf("\nPago a profesor: %f",SalMenosImp);
       NOM = NOM + SAL;
       //NOM += SAL;
    }
    printf("\nTotal a Pagar: %.2f", NOM);
    printf("\nTotal a Pagar profesores: %.2f",NOM - (NOM * 0.12));
    printf("\nTotal de impuestos: %.2f", NOM * 0.12);
    printf("\nTotal a pagar de impuestos es: %.2f",NOM);

    return 0;
}
