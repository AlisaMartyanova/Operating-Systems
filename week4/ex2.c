/*
ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
    │     │     │     └─ex2
    │     │     ├─ex2───ex2
    │     │     └─ex2
    │     ├─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2─┬─ex2───ex2
    │     │     └─ex2
    │     ├─ex2───ex2
    │     └─ex2
    ├─ex2─┬─ex2───ex2
    │     └─ex2
    ├─ex2───ex2
    └─ex2

number of processes = 2^n = 2^5 = 32
*/

#include <stdio.h>
#include <sys/types.h>

int main(){
	for(int i = 0; i<5; i++){
		fork();
		sleep(5);
	}

	return 0;
}
