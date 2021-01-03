#include "libft.h"
//실패
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize)
	{
		while (++i < dstsize - 1 && src[i])
			dest[i] = src[i];
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

//통과
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}