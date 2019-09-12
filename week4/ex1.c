/*
fork() launch new process which has its own id
so, our parent and first child have the same id cause they are one process
and second child has another id cause it is another process, launched by fork()
also in each iteration we launch new process so on each iteration our processes have different id
*/

#include <stdio.h>
#include <sys/types.h>

int main(){
	pid_t n = getpid();
	printf("Hello from parent [PID - %d]\n", n);	
	fork();
	n = getpid();
	printf("Hello from child [PID - %d]\n", n);
	sleep(1);
	printf("\n");
	return 0;
}
