#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("Before\n");
	execl("/bin/ls", "ls", "-l", NULL);
	printf("After\n");
}
