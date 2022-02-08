#include "ft_printf_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_substr (char const *str, int start, int len, int	i)
{
	char	*sub;

	if (str == NULL)
		return (NULL);
	if (start >= ft_strlen((char *)str))
	{
		sub = ft_calloc(1, sizeof(char));
		if (sub == NULL)
			return (NULL);
		return (sub);
	}
	if (len > ft_strlen((char *)str))
		len = ft_strlen((char *)str);
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && str[start + i] != '\0')
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	*ft_calloc(int count, int size)
{
	void	*result;
	int		i;

	i = 0;
	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	while (i <= count * size)
		((char *)result)[i++] = 0;
	return (result);
}
