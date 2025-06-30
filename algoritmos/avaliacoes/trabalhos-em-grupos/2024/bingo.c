#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cartelas() {
    srand(time(NULL));
    int mtz1[3][5], mtz2[3][5], mtz3[3][5];
    int i, j, k, r, x, y = 0, p = 0, z = 0, c;

    //cartelas
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            mtz1[i][j] = 0;
            mtz2[i][j] = 0;
            mtz3[i][j] = 0;
        }
    }

    //cartela 1
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            do {
                mtz1[i][j] = rand() % 60 + 1;
                r = 0;
                for (k = 0; k < i * 5 + j; k++) {
                    if (mtz1[i][j] == mtz1[k / 5][k % 5]) {
                        r = 1;
                        break;
                    }
                }
            } while (r);
            printf("[%2d]", mtz1[i][j]);
        }
        printf("\n");
    }

    //cartela 2
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            do {
                mtz2[i][j] = rand() % 30 * 2 + 1;
                r = 0;
                for (k = 0; k < i * 5 + j; k++) {
                    if (mtz2[i][j] == mtz2[k / 5][k % 5]) {
                        r = 1;
                        break;
                    }
                }
            } while (r);
            printf("[%2d]", mtz2[i][j]);
        }
        printf("\n");
    }

    //cartela 3
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            do {
                mtz3[i][j] = rand() % 15 * 4 + 1;
                r = 0;
                for (k = 0; k < i * 5 + j; k++) {
                    if (mtz3[i][j] == mtz3[k / 5][k % 5]) {
                        r = 1;
                        break;
                    }
                }
            } while (r);
            printf("[%2d]", mtz3[i][j]);
        }
        printf("\n");
    }

	//sorteando
    do {
    	printf("Pressione 'a' para gerar um numero aleatorio: ");
        c = getchar();
        getchar();
        if(c == 'a')
        {
		
        x = rand() % (5 * 12) + 1;
        printf("Numero sorteado: %d\n", x);


        for (i = 0; i < 3; i++) {
            for (j = 0; j < 5; j++) {
                if (x == mtz1[i][j]) {
                    mtz1[i][j] = 0;
                    y++;
                } else if (x == mtz2[i][j]) {
                    mtz2[i][j] = 0;
                    p++;
                } else if (x == mtz3[i][j]) {
                    mtz3[i][j] = 0;
                    z++;
                }
            }
        }

        printf("Cartela do Jogador 1:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 5; j++) {
                printf("[%2d]", mtz1[i][j]);
            }
            printf("\n");
        }

        printf("Cartela do Jogador 2:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 5; j++) {
                printf("[%2d]", mtz2[i][j]);
            }
            printf("\n");
        }

        printf("Cartela do Jogador 3:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 5; j++) {
                printf("[%2d]", mtz3[i][j]);
            }
            printf("\n");
        }
    }
	} while (y < 15 && p < 15 && z < 15);

    //vencedor
    if (y == 15) {
        printf("Jogador 1 gritou: BINGO!\n");
    } else if (p == 15) {
        printf("Jogador 2 gritou: BINGO!\n");
    } else if (z == 15) {
        printf("Jogador 3 gritou: BINGO!\n");
    }
}

int main() {
    cartelas();
    return 0;
}
