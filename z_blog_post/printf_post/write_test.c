#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
	unsigned long a = 9999999;
	unsigned long i;
	float res1;
	char *str;
	clock_t start, end;
	start = clock();


		write(1, "a", 1);
//	str = malloc(a + 1);
//	memset(str, 'a', a);
//	write(1, str, a);
	end = clock();
	res1 = (float)(end - start)/CLOCKS_PER_SEC;
	printf("%f", res1);
	return (0);
}
if
if
if
if


if
{
	if
	
	else
}
else
{
	if
	
	else
}
