#include<stdio.h>

int main(){
	int n = 1;
	while((n*55) % 24 != 1){
		n++;
	}
	n = 10000000 % 35;
	printf("%d\n",n);
	return 0;
}