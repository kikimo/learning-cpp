#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int i;
	for (i = 0; i < 40960; i++) {
		char *buf = malloc(4096);
		printf("allocating %d, 4096 bytes\n", i);
		if (buf == 0) {
			perror("failed alloc mem");
			return 1;
		}
		sleep(1);
	}

	return 0;
}
