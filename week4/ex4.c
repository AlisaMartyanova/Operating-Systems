// More universal implementation of shell

#include <stdio.h>
#include <sys/types.h>
#include <string.h>

int main(){
	printf("************************************\nWelcome to this shell!             *\nWrite your commands after '>'.     *\nIf you want to exit enter 'q'.     *\n************************************\n");
	while(1){
		printf("> ");
		char str[128];
		fgets(str,128, stdin);

		if(strcmp(str, "q\n") == 0){return;}
		else {system(str);}
	}

	return 0;
}
