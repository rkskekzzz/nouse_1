//read_smallbuf.c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1

int main(void)
{
	char buf[BUFFER_SIZE + 1];
	int fd;
	int temp_read_size = 0;

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error");
	else
	{
		while ((temp_read_size = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			printf("%s", buf);
			memset(buf, 0, BUFFER_SIZE);
		}
		close(fd);
	}
	return(0);
}
