#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 8

void imprimirTablero(char t[SIZE][SIZE])
{
    printf("\n    0   1   2   3   4   5   6   7\n");
    for (int r = 0; r < SIZE; r++)
    {
        printf(" %d ", r);
        for (int c = 0; c < SIZE; c++)
        {
            if ((r + c) % 2 == 0) printf("[%-2c]", t[r][c]);
            else printf("{%-2c}", t[r][c]);
        }
        printf("\n");
    }
}

//función caminoLibre y movimientoValido del paso anterior
int caminoLibre(char t[SIZE][SIZE], int r1, int c1, int r2, int c2)
{
    int dr = (r2 > r1) ? 1 : (r2 < r1) ? -1 : 0;
    int dc = (c2 > c1) ? 1 : (c2 < c1) ? -1 : 0;
    int r = r1 + dr, c = c1 + dc;
    while (r != r2 || c != c2)
    {
        if (t[r][c] != ' ') return 0;
        r += dr;
        c += dc;
    }
    return 1;
}

int movimientoValido(char t[SIZE][SIZE], int r1, int c1, int r2, int c2, int turno);

// Está el rey del turno actual en jaque?
int enJaque(char t[SIZE][SIZE], int turno)
{
    char rey = turno == 0 ? 'R' : 'r';
    int rr = -1, cc = -1;

    // localizar al rey
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            if (t[r][c] == rey)
            {
                rr = r;
                cc = c;
            }

    // buscar si alguna pieza enemiga lo amenaza
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            if (t[r][c] != ' ' && ((turno == 0 && islower(t[r][c])) || (turno == 1 && isupper(t[r][c]))))
                if (movimientoValido(t, r, c, rr, cc, 1 - turno)) return 1;

    return 0;
}

int movimientoValido(char t[SIZE][SIZE], int r1, int c1, int r2, int c2, int turno)
{
    char p = t[r1][c1];
    char destino = t[r2][c2];
    int dr = abs(r2 - r1), dc = abs(c2 - c1);

    if (r1 == r2 && c1 == c2) return 0;
    if (destino != ' ' && ((turno == 0 && isupper(destino)) || (turno == 1 && islower(destino)))) return 0;

    switch (toupper(p))
    {
    case 'P':
        if (turno == 0)
        {
            if (c1 == c2 && t[r2][c2] == ' ')
            {
                if (r2 == r1 - 1) return 1;
                if (r1 == 6 && r2 == 4 && t[5][c1] == ' ') return 1;
            }
            else if (dr == 1 && dc == 1 && r2 == r1 - 1 && t[r2][c2] != ' ') return 1;
        }
        else
        {
            if (c1 == c2 && t[r2][c2] == ' ')
            {
                if (r2 == r1 + 1) return 1;
                if (r1 == 1 && r2 == 3 && t[2][c1] == ' ') return 1;
            }
            else if (dr == 1 && dc == 1 && r2 == r1 + 1 && t[r2][c2] != ' ') return 1;
        }
        break;
    case 'T':
        if (r1 == r2 || c1 == c2) return caminoLibre(t, r1, c1, r2, c2);
        break;
    case 'C':
        if ((dr == 2 && dc == 1) || (dr == 1 && dc == 2)) return 1;
        break;
    case 'A':
        if (dr == dc) return caminoLibre(t, r1, c1, r2, c2);
        break;
    case 'M':
        if (r1 == r2 || c1 == c2 || dr == dc) return caminoLibre(t, r1, c1, r2, c2);
        break;
    case 'R':
        if (dr <= 1 && dc <= 1) return 1;
        break;
    }
    return 0;
}

// Existen movimientos legales que salven al rey?
int hayMovimientoLegal(char t[SIZE][SIZE], int turno)
{
    for (int r1 = 0; r1 < SIZE; r1++)
        for (int c1 = 0; c1 < SIZE; c1++)
        {
            char p = t[r1][c1];
            if (p == ' ') continue;
            if ((turno == 0 && isupper(p)) || (turno == 1 && islower(p)))
            {
                for (int r2 = 0; r2 < SIZE; r2++)
                    for (int c2 = 0; c2 < SIZE; c2++)
                        if (movimientoValido(t, r1, c1, r2, c2, turno))
                        {
                            char temp = t[r2][c2];
                            t[r2][c2] = p;
                            t[r1][c1] = ' ';
                            int jaque = enJaque(t, turno);
                            t[r1][c1] = p;
                            t[r2][c2] = temp;
                            if (!jaque) return 1;
                        }
            }
        }
    return 0;
}

int main()
{
    char t[SIZE][SIZE] =
    {
        {'t','c','a','m','r','a','c','t'},
        {'p','p','p','p','p','p','p','p'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'P','P','P','P','P','P','P','P'},
        {'T','C','A','M','R','A','C','T'}
    };

    int turno = 0;
    int r1, c1, r2, c2;

    while (1)
    {
        imprimirTablero(t);
        if (enJaque(t, turno))
        {
            printf("El rey de %s esta en jaque!\n", turno == 0 ? "blancas" : "negras");
            if (!hayMovimientoLegal(t, turno))
            {
                printf("Jaque mate! %s ganan.\n", turno == 0 ? "negras" : "blancas");
                break;
            }
        }

        printf("\nTurno de %s\n", turno == 0 ? "blancas" : "negras");
        printf("Origen (fila col): ");
        scanf("%d %d", &r1, &c1);
        if (r1 < 0 || r1 >= SIZE || c1 < 0 || c1 >= SIZE) continue;

        char pieza = t[r1][c1];
        if (pieza == ' ') continue;
        if ((turno == 0 && !isupper(pieza)) || (turno == 1 && !islower(pieza))) continue;

        printf("Destino (fila col): ");
        scanf("%d %d", &r2, &c2);
        if (r2 < 0 || r2 >= SIZE || c2 < 0 || c2 >= SIZE) continue;

        if (movimientoValido(t, r1, c1, r2, c2, turno))
        {
            // Simular movimiento y verificar jaque
            char temp = t[r2][c2];
            t[r2][c2] = pieza;
            t[r1][c1] = ' ';
            if (!enJaque(t, turno))
            {
                turno = 1 - turno;
            }
            else
            {
                printf("No puedes dejar a tu rey en jaque.\n");
                t[r1][c1] = pieza;
                t[r2][c2] = temp;
            }
        }
        else
        {
            printf("Movimiento invalido.\n");
        }
    }

    return 0;
}
