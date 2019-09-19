#include <stdio.h> 
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h>
#include <time.h>

int buffer[10];
int i = 0;

void* thread_producer(void *vararg)
{
	srand(time(NULL));
	
	int chislo = rand()/4574;
	if(i<10){
		buffer[i] = chislo;
		//printf("produce: %d\n", buffer[i]);
		i++;

	}

}

void* thread_consumer(void *vararg)
{

	if(i>0){
		i--;
		//printf("consume: %d\n", buffer[i]);
		buffer[i] = 0;
	}

}


int main(){
	int n;

	while (1){
		
		srand(time(NULL));
		n = rand()/100000000;
		if (n>11){
			pthread_t id1;		
			pthread_create(&id1, NULL, thread_producer, &id1);
			//sleep(1);
			pthread_join(id1, NULL);
		}else{
			pthread_t id2;		
			pthread_create(&id2, NULL, thread_consumer, &id2);
			//sleep(1);
			pthread_join(id2, NULL);
		}
	}


	return 0;
}
