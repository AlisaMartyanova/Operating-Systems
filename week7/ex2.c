#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	printf("Enter number N:\n");
	scanf("%d", &N);
	
	int* arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i<N; i++){
		arr[i] = i;
	}

	for (int i = 0; i<N; i++){
		printf("%d ", arr[i]);
	}
 	printf("\n");
 	free(arr);

	return 0;
}
