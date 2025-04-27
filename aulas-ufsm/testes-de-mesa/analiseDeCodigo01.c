#include <stdio.h>

int analise(int x){
	printf("%d\n", x);
	x--;
	return x;
}

int main(){
	int i;
	int t=10;
	
	for(i=0;i<t;i++){
		t = analise(t);
	}
	
	return 0;
}