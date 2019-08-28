#include <stdio.h>
#include <string.h>

void reverse(char a[], char b[]){
	for (int i = 0; i<strlen(a); i++){
		b[strlen(a)-i] = a[i];
	}
}

int main(){
	char str[1000];
	char new[1000] = "\t";

	printf("Enter the string:\n");
	fgets(str, 127, stdin);
	reverse(str, new);
	printf("%s\n", new);
	
}
