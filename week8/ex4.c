#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main(){

    struct rusage p;

    int size = 10;
    for (size_t i = 0; i < 10; i++)
    {
        memset(malloc(size * 1024 * 1024), '0', size * 1024 * 1024);

	if(getrusage(RUSAGE_SELF, &p) == 0){
            printf("used: %ld KB\n", p.ru_maxrss);
        } else {
            printf("error\n");
        }
        sleep(1);
    }

    return 0;
}
