#include <stdio.h>

int analise(int x){
	x--;
	return x;
}

int main(){
	
	int i,n=5;
	int v[n];

	for (i=0;i<n;i++){
		v[i] = analise(i+10);
	}
	
	for (i = n-1;i>=0;i--){
		printf("%d\n", v[i]);
	}
	
	return 0;
}