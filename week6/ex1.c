#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){
    int buf[2];
	char str1[100] = "Hello! Be happy:)";
	char str2[100];
	
    pipe(buf);
    printf("Before pipe:\nfisrt string is '%s'\nsecond string is '%s'\n", str1, str2);
	write(buf[1], str1, (strlen(str1)+1));
	read(buf[0], str2, (strlen(str1)+1));
	printf("After pipe:\nfisrt string is '%s'\nsecond string is '%s'\n", str1, str2);

	return 0;
}
