#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	int fd2;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	if (fd < 1 || fd2 < 1)
	{
		printf("open() error");
		exit(1);
	}
	printf("fd\t: %d\n", fd);
	printf("fd2\t: %d\n", fd2);

	printf("fd2 = dup(fd)\n");
	fd2 = dup(fd);
	
	printf("fd\t: %d\n", fd);
	printf("fd2\t: %d\n", fd2);

	close(fd);
	close(fd2);
	return (0);
}
