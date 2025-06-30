#include <stdio.h>

int calcula(int x){
    x += 2;
    return x;
}

int main(){
    int i, n = 4;
    int v[n];
    for(i = 0; i < n; i++){
        v[i] = calcula(i * 3);
    }
    printf("\n");
    for(i = n-1; i >= 0; i--){
        printf("%d\t", v[i]);
    }
    return 0;
}