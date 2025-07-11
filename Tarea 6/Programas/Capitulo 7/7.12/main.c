#include <stdio.h>
#include <ctype.h>
#include <string.h>



int main(void)
{
    char cad[50];
    int i = 0, mi = 0, ma = 0;

    printf("\nIngrese la cadena de caracteres (maximo 50 caracteres): ");
    fgets(cad, sizeof(cad), stdin);
    cad[strcspn(cad, "\n")] = '\0';
    while (cad[i] != '\0')
    {
        if (islower(cad[i]))
            mi++;
        else if (isupper(cad[i]))
            ma++;
        i++;
    }

    printf("\n\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d\n", ma);

    return 0;
}
