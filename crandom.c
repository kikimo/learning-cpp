#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int val = 0;

	srand(time(NULL));
	val = rand();
	printf("rand val: %d\n", val);

	return 0;
}
