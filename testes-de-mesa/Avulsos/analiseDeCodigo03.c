#include <stdio.h>

int soma(int x){
    return x + 5;
}

int main(){
    int i, n = 6;
    int v[n];
    for(i = 0; i < n; i++){
        v[i] = soma(i);
    }
    for(i = n-1; i >= 0; i--){
        printf("%d ", v[i]);
    }
    return 0;
}