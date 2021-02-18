#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1

char *str_append(char *save, char *buf);

int main(void)
{
	int fd;
	char buf[BUFFER_SIZE + 1];
	char *save;
	int temp_read_size = 0;

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
		printf("file open error");
	else
	{
		while ((temp_read_size = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[temp_read_size] = '\0';
			save = str_append(save, buf);

		}
		printf("%s", save);
		close(fd);
	}
	return(0);
}

char *str_append(char *save, char *buf)
{
	char *temp;

	if (!save && !buf)
		return (NULL);
	if (!save)
		return strdup(buf);
	if (!buf)
		return (save);
	return strcat(save, buf);
}
