#include <stdio.h>
#include <stdlib.h>
#define MENU_NINGUNO 0
#define MENU_SUMAR 2
#define MENU_DIVIDIR 3
#define MENU_SALIR 1
int main()
{
    float n1 = 0.0, n2 = 0.0, result = 0.0;
    int menu = MENU_NINGUNO;

    do
    {
        printf("\n1-Salir\n2-Sumar\n3-Dividir\n");
        scanf("%i",&menu);

        if(menu == MENU_SUMAR)
        {
            printf("\nPrimer sumando: ");
            scanf("%f",&n1);
            printf("\nSegundo sumando: ");
            scanf("%f",&n2);
            result = n1+n2;
            printf("\nSuma de %f es:%f",n1,n2,result);
        }
        if(menu == MENU_DIVIDIR)
        {
            printf("\nPrimer dividendo: ");
            scanf("%f",&n2);
            printf("\nSegundo dividendo: ");
            scanf("%f",&n2);
            result = n1/n2;
            printf("\division de %f es:%f",n1,n2,result);
        }
        if(menu < 1 || menu > 3)
        {
            printf("\nMenu no valido 1 - 3");
        }

    }
while (menu != MENU_SALIR);

    return 0;
}
