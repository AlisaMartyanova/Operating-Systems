#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

int n = 1;
int N = 5;
void *thread_func(void *vararg){
	printf("I'm thread %d, hello!\n", n);
	n++;
	pthread_exit(0);
}

int main(){


	for (int i = 1; i<N+1; i++){
		pthread_t thread;
		pthread_create(&thread, NULL, thread_func, NULL);
		printf("Thread %d created\n", i);
		pthread_join(thread, NULL);
		printf("Tread %d exited\n", i);

	}
	

	return 0;
}
