//read.c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char buf[100];

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error");
	else
	{
		read(fd, buf, sizeof(buf));
		printf("%s", buf);
		close(fd);
	}
	return(0);
}
