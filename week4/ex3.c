//simple implementation of shell with few number of commands

#include <stdio.h>
#include <sys/types.h>
#include <string.h>

int main(){
	printf("*****************************************************\nWelcome to this shell!           		    *\nWrite your commands after '>'     		    *\nTo see the list of possible commands enter 'system' *\nIf you want to exit enter 'q'    		    *\n*****************************************************\n");
	while(1){
		printf("> ");
		char str[128];
		fgets(str,128, stdin);

		if(strcmp(str, "q\n") == 0){return;}
		else if (strcmp(str, "system\n") == 0){
			printf("ls\npwd\ntop\npstree\ndf\ndate\n");
		}
		else if (strcmp(str, "ls\n") == 0){system("ls");}
		else if (strcmp(str, "pwd\n") == 0){system("pwd");}
		else if (strcmp(str, "top\n") == 0){
			printf("If you want to exit 'top' enter 'q'\n");
			system("top");
		}
		else if (strcmp(str, "pstree\n") == 0){system("pstree");}
		else if (strcmp(str, "df\n") == 0){system("df");}
		else if (strcmp(str, "date\n") == 0){system("date");}
		else if (strcmp(str, "\n") == 0){;}
		else {printf("Invalid command\n");}
	}	
	
	
	
	return 0;
}
