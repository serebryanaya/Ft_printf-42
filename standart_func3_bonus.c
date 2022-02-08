#include "ft_printf_bonus.h"

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dstsize > 0)
	{
		while ((src[i] != '\0') && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(char *str)
{
	char	*dup;

	dup = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, str, ft_strlen(str) + 1);
	return (dup);
}

int	count_num(unsigned int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}
