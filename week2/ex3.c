#include <stdio.h>

int main(){
	int n;
	printf("Enter the number n:\n");
	scanf("%d", &n);

	char arr[2*n-1];

	for (int i = 0; i<n; i++){
		int num_stars = 2*(i+1)-1;
		int num_spaces = (2*n-1-num_stars)/2;
		for(int j = 0; j<num_spaces; j++){
			arr[j] = ' ';
		}
		for (int k = num_spaces; k<num_spaces+num_stars; k++){
			arr[k] = '*';
		}
		for (int h = 0; h<num_spaces+num_stars; h++){
			printf("%c", arr[h]);		
		}
		printf("\n");
	}



}
