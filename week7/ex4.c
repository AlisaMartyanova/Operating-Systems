#include <stdio.h>
#include <stdlib.h>

void my_realloc(int** arr, int len, int newlen){
	int* temp = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i<len; i++){
		temp[i] = (*arr)[i];
	} 
	free(*arr);
	*arr = (int*)malloc(sizeof(int)*newlen);
	for (int i = 0; i<len; i++){
		(*arr)[i] = temp[i];
	}
	for (int i = len; i<newlen; i++){
		(*arr)[i] = 0;
	}
	free(temp);
}

int main(){
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);
	
	int* a1 = (int*)malloc(sizeof(int)*n1);
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ",a1[i] );
	}
	
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);
	my_realloc(&a1, n1, n2);
	
	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}
	printf("\n");

	return 0;
}
