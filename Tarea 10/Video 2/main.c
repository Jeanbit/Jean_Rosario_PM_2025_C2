#include <stdio.h>
#include <stdlib.h>

 int main()
{
  /* int num = 10;
    int num2 = 100;

    printf("El numero vale: %d\n", num);

    int *pnum = &num;
    *pnum = 12;
    printf("El numero vale: %d\n", num);

     int **ppnum = &pnum;
    **ppnum = 14;
    printf("El numero vale: %d\n", num);

    *ppnum = &num2;
    printf("El numero vale: %d\n", num2);
    *pnum = 120;
     printf("El numero vale: %d\n", num2);
    **ppnum = 1200;
     printf("El numero vale: %d\n", num2);*/
int *arreglo;
CyRetornar3(&arreglo,10);
motrar(arreglo);


 void CyRetornar3(int **a, int dim)
{
    *a = malloc(dim*sizeof(int));
    for(int i=0; i<dim;i++)
    {
        (*a)[i]=i+1;
    }
}
void CyRetornar2(int *a)
{
    for(int i=0;i<10;i++)
    {
        a[i]=i+1;
    }
}
int * CyRetornar()
{
    int *a = malloc(10*sizeof(int));
    for (int i=0; i<10; i++)
    {
        a[i]=i+1;
    }
}
}
