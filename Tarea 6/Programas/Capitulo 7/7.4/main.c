#include <stdio.h>
#include <string.h>
#define TAM 100

int main(void)
{

    const char *cad0 = "Argentina";
    puts(cad0);

    cad0 = "Brasil";
    puts(cad0);


    char cad1[TAM];
    printf("\nIngrese una cadena para cad1: ");
    fgets(cad1, TAM, stdin);
    cad1[strcspn(cad1, "\n")] = '\0';
    puts(cad1);


    char cad2[20] = "Mexico";
    puts(cad2);

    printf("\nIngrese una nueva cadena para cad2 (max 19 caracteres): ");
    fgets(cad2, 20, stdin);
    cad2[strcspn(cad2, "\n")] = '\0';
    puts(cad2);


    strcpy(cad2, "Guatemala");
    puts(cad2);

    return 0;
}
