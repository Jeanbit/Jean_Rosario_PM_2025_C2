#include <stdio.h>
#include <stdlib.h>



int a, b, c, d;

void funcion1(int, int *, int *);
int funcion2(int *, int);

int main(void)
{
    int a;
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    printf("\n%d %d %d %d", a, b, c, d);
    a = funcion2(&a, c);
    printf("\n%d %d %d %d", a, b, c, d);

    return 0;
}

void funcion1(int r, int *b, int *c)
{
    int d_local;
    a = *c;
    d_local = a + 3 + *b;
    if (r)
    {
        *b = *b + 2;
        *c = *c + 3;
        printf("\n%d %d %d %d", a, *b, *c, d_local);
    }
    else
    {
        *b = *b + 5;
        *c = *c + 4;
        printf("\n%d %d %d %d", a, *b, *c, d_local);
    }
}

int funcion2(int *d_ptr, int c_val)
{
    int b_local;
    a = 1;
    b_local = 7;
    funcion1(-1, d_ptr, &b_local);
    printf("\n%d %d %d %d", a, b_local, c_val, *d_ptr);
    c_val += 3;
    (*d_ptr) += 2;
    printf("\n%d %d %d %d", a, b_local, c_val, *d_ptr);
    return c_val;
}
