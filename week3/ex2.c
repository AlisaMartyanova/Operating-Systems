#include <stdio.h>

void bubble_sort(int arr[], int size){
	int temp;
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size - i - 1; ++j){
			if(arr[j] > arr[j+1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
		
	}
	

}

int main(){
	int a[5] = {3,6,1,8,4};

	for (int i = 0; i<5; i++){
		printf("%d", a[i]);
	}
	printf("\n");
	bubble_sort(a, 5);

	for (int i = 0; i<5; i++){
		printf("%d", a[i]);
	}
	printf("\n");
	
}
