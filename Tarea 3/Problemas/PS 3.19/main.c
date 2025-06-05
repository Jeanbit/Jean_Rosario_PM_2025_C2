#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n = 10;

    for (i = 1; i <= n; i++)
        {
        for (j = 1; j <= n - i; j++) {
            printf("  ");
        }

        for (j = 0; j < i; j++) {
            printf("%d ", (i + j) % 10);
        }

        for (j = i - 2; j >= 0; j--) {
            printf("%d ", (i + j) % 10);
        }

        printf("\n");
    }

    return 0;
}
