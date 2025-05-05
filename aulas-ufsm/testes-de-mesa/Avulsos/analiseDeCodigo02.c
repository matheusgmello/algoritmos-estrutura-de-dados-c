#include <stdio.h>

int multiplica(int x){
    return x * 2;
}

int main(){
    int i, n = 3;
    int v[n];
    for(i = 0; i < n; i++){
        v[i] = multiplica(i + 4);
    }
    for(i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}