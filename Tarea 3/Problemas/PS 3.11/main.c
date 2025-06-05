#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    float VIN[100][4];
    float total_tipo[4] = {0, 0, 0, 0};
    float total_anual[100] = {0};

    printf("Ingrese el numero de anos: ");
    scanf("%d", &N);


    for (int i = 0; i < N; i++) {
        printf("\nAno %d:\n", i + 1);
        for (int j = 0; j < 4; j++) {
            printf("  Litros de vino tipo %d: ", j + 1);
            scanf("%f", &VIN[i][j]);
            total_tipo[j] += VIN[i][j];
            total_anual[i] += VIN[i][j];
        }
    }


    printf("\n--- Total producido por tipo de vino ---\n");
    for (int j = 0; j < 4; j++) {
        printf("Tipo %d: %.2f litros\n", j + 1, total_tipo[j]);
    }

    printf("\n--- Total producido por ano ---\n");
    for (int i = 0; i < N; i++) {
        printf("Ano %d: %.2f litros\n", i + 1, total_anual[i]);
    }

    return 0;
}
