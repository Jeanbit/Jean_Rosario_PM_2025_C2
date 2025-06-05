#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var = 0;
//Inicializacion;logica; actualizacion
    for(var = -10;var <= 10;var++)
    {
        if(var != 0)
        {
          printf("Valor de Var: %i\n",var);
        }

    }
    printf("Fin de programa");
    return 0;
}
