#include <stdio.h>
#include <stdlib.h>

int main()
{
    float precios[6];
    int boletos[6] = {0, 0, 0, 0, 0, 0};
    int CLA, CAN;
    float monto, recaudacion_total = 0;


    printf("Ingrese los precios de las 6 localidades:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Precio L%d: ", i + 1);
        scanf("%f", &precios[i]);
    }

    printf("\nIngrese tipo de localidad (1-6) y cantidad de boletos. Use 0 0 para terminar.\n");

    while (1)
    {
        printf("Tipo de localidad (CLA): ");
        scanf("%d", &CLA);
        printf("Cantidad de boletos (CAN): ");
        scanf("%d", &CAN);

        if (CLA == 0 && CAN == 0)
            break;

        if (CLA < 1 || CLA > 6 || CAN < 0)
        {
            printf("Entrada inválida.\n");
            continue;
        }

        monto = precios[CLA - 1] * CAN;
        boletos[CLA - 1] += CAN;
        recaudacion_total += monto;

        printf("Monto de esta venta: $%.2f\n", monto);
    }


    printf("\n--- Resumen de Ventas ---\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Boletos vendidos L%d: %d\n", i + 1, boletos[i]);
    }
    printf("Recaudación total: $%.2f\n", recaudacion_total);

    return 0;
}
