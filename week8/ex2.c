#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    int size = 10;
    for (size_t i = 0; i < 10; i++)
    {
        memset(malloc(size * 1024 * 1024), '0', size * 1024 * 1024);
        sleep(1);
    }

    return 0;
}
