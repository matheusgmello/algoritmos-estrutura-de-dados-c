#include <stdio.h>
#include <stdlib.h>

int main(){
    int MA[8][8];
    int MB[8][8];
    int i,j;

    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            MA[i][j] = rand() % 100 + 1;
        }
    }

    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            if(j ==0 ){
                MB[i][j] = MA[i][j];
            } else if (j > 0) {
                MB[i][j] = MA[i][j-1] * 2;
            }  else if (i > 0) {
                MB[i][j] = MA[i-1][j] * 2;
			}
        }
    }

    printf("matriz a\n");
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            printf("%d\t", MA[i][j]);
        }
        printf("\n");
    }

    printf("matriz b\n");
    for (i=0;i<8;i++){
        for (j=0;j<8;j++){
            printf("%d\t", MB[i][j]);
        }
        printf("\n");
    }

    return 0;
}