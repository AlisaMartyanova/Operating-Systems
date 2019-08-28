#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a;
	float b;
	double c;

	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;

	printf("a = %d, size of a: %lu\nb = %f, size of b: %lu\nc = %g, size of c: %lu\n", a, sizeof(a), b, sizeof(b), c, sizeof(c));
}
