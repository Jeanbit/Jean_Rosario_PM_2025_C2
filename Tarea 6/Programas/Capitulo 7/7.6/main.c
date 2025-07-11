#include <stdio.h>
#include <string.h>


int main(void)
{
    char cad0[50] = "Hola Mexico";
    char cad1[50], cad2[50], cad3[50] = ", buenos dias!!!";

    strcpy(cad1, cad0);
    printf("\nPrueba de strcpy. Se copia la cadena cad0 a cad1: %s\n", cad1);

    strcpy(cad1, cad3);
    printf("Prueba de strcpy. Se copia la cadena cad3 a cad1: %s\n", cad1);

    strcpy(cad1, "XX");
    printf("Prueba de strcpy. Se copia la cadena 'XX' a cad1: %s\n", cad1);

    strncpy(cad2, cad0, 4);
    cad2[4] = '\0';
    printf("Prueba de strncpy. Se copian 4 caracteres de cad0 a cad2: %s\n", cad2);

    strncpy(cad2, cad3, 3);
    cad2[3] = '\0';
    printf("Prueba de strncpy. Se copian 3 caracteres de cad3 a cad2: %s\n", cad2);

    strcat(cad0, cad3);
    printf("Prueba de strcat. Se incorpora la cadena cad3 a cad0: %s\n", cad0);

    strcat(cad1, " YY");
    printf("Prueba de strcat. Se incorpora la cadena 'YY' a cad1: %s\n", cad1);

    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    printf("Prueba de strncat. Se incorporan 4 caracteres de cad0 a cad2: %s\n", cad2);

    char *ptr;

    ptr = strstr(cad0, "Mexico");
    if (ptr)
        printf("Prueba de strstr. Se encontr� 'Mexico' en cad0: %s\n", ptr);
    else
        printf("No se encontr� 'Mexico' en cad0.\n");

    ptr = strstr(cad0, "Guatemala");
    if (ptr)
        printf("Prueba de strstr. Se encontr� 'Guatemala' en cad0: %s\n", ptr);
    else
        printf("No se encontr� 'Guatemala' en cad0.\n");

    return 0;
}
