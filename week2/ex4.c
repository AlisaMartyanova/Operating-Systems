#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int a,b;
	printf("Enter two integers:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
}
