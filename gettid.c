#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main()
{
	pid_t tid = syscall(__NR_gettid);
	printf("tid: %d\n", tid);
	return 0;
}
