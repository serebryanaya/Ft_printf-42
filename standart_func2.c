#include "ft_printf.h"

int	ft_atoi_mod(char *s, int i, int sign, t_list *in)
{
	unsigned int	number;

	number = 0;
	while (s[i] == '-')
	{
		in->minus = 1;
		sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		number = 10 * number + (s[i++] - '0');
	if (in->minus != 1 && (number > 2147483648))
		number = 0;
	if (sign == -1)
		return (-1 * (int)number);
	else
		return ((int)number);
}

char	*minimus(char *minimum)
{
	char	*number;
	int		i;

	minimum = "-2147483648";
	i = 0;
	number = malloc(sizeof(char) * 12);
	while (minimum[i] != '\0')
	{
		number[i] = minimum[i];
		i++;
	}
	number[i] = '\0';
	return (number);
}

char	*ft_itoa_mod1(int integer, int rank, t_list *in)
{
	char	*number;
	int		copy;

	if (integer == -2147483648)
		return (minimus("-2147483648"));
	copy = integer;
	while (copy / 10 != 0)
	{
		rank++;
		copy /= 10;
	}
	if (integer < 0)
		rank++;
	number = malloc(sizeof(char) * (rank + 1));
	if (!number)
		return (NULL);
	number = ft_itoa_mod2(integer, rank, number, in);
	return (number);
}

char	*ft_itoa_mod2(int integer, int rank, char *number, t_list *in)
{
	number[rank--] = '\0';
	if (in->sign == -1 && rank > 0)
	{
		number[0] = '-';
		integer *= -1;
	}
	if ((rank > 0 && in->sign == -1) || (rank >= 0 && in->sign != -1))
	{
		while (integer / 10)
		{
			number[rank] = integer % 10 + 48;
			rank--;
			integer /= 10;
		}
		number[rank] = integer % 10 + 48;
	}
	return (number);
}

void	space_or_nul_print(t_list *in, int i, int len, int flag)
{
	while (i++ < len)
	{
		if (flag == 1)
			in->count += write(1, " ", 1);
		else
			in->count += write(1, "0", 1);
	}
}
