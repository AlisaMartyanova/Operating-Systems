#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){

	int buf[2];
	char str1[100] = "Hello! Be happy:)";
	char str2[100];
	pipe(buf);

	pid_t   childpid;
	if(childpid = fork() == 0)
                {
                        /* Child process closes up input side of pipe */
			read(buf[0], str2, (strlen(str1)+1));
			printf("str2: '%s'\n", str2);
                        close(buf[0]);
                }
                else
                {
                        /* Parent process closes up output side of pipe */
			write(buf[1], str1, (strlen(str1)+1));
                        close(buf[1]);
                }



	return 0;
}
