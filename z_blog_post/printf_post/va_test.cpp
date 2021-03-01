#include <stdio.h>
#include <stdarg.h>

void sumAll(int args, ...)
{
	int result;
	int tmp;
	//va_list ap;
	char *ap;

	result = 0;
	//va_start(ap, args);
	ap = (char *)&args + sizeof(args);
	for (int i = 0 ; i < args ; i++)
	{
		//tmp = va_arg(ap, int);
		tmp = *((int *)ap);
		ap += sizeof(int);
		result += tmp;
		printf("%d", tmp);
		if (i == args - 1)
			break;
		printf(" + ");
	}
	printf(" = %d\n", result);
	//va_end(ap);
	ap = 0;
}

int main(void)
{
	sumAll(1, 10);
	sumAll(2, 10, 20);
	sumAll(3, 10, 20, 30);
	sumAll(4, 10, 20, 30, 40);
	sumAll(5, 10, 20, 30, 40, 50);

	return (0);
}
