#include <stdio.h>
#include <stdlib.h>



int F1(int, int *);

int A = 3;
int B = 7;
int C = 4;
int D = 2;

int main(void)
{
    A = F1(C, &D);
    printf("\n%d %d %d %d", A, B, C, D);
    C = 3;
    C = F1(A, &C);
    printf("\n%d %d %d %d", A, B, C, D);

    return 0;
}

int F1(int X, int *Y)
{
    int A_local;
    A_local = X * (*Y);
    C++;
    B += *Y;
    printf("\n%d %d %d %d", A_local, B, C, D);
    (*Y)--;
    return C;
}
