#include "ft_printf.h"

void	is_unsigned1(va_list arg, t_list *in)
{
	unsigned int	num;
	char			*number;
	int				len;

	num = va_arg(arg, unsigned int) + 4294967295 + 1;
	number = ft_u_itoa_mod1(num, 1, in);
	if (number == NULL)
	{
		in->count = -1;
		return ;
	}
	len = ft_strlen(number);
	init_info_int(in, &len, number);
	is_int2(in, number, &len, 0);
	if (number != NULL)
		free(number);
}

char	*ft_u_itoa_mod1(unsigned int integer, int rank, t_list *in)
{
	char			*number;
	unsigned int	copy;

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
	number = ft_uns_itoa_mod2(integer, rank, number, in);
	return (number);
}

char	*ft_uns_itoa_mod2(unsigned int i, int rank, char *number, t_list *in)
{
	number[rank--] = '\0';
	if (in->sign == -1 && rank > 0)
	{
		number[0] = '-';
		i = -1;
	}
	if ((rank > 0 && in->sign == -1) || (rank >= 0 && in->sign != -1))
	{
		while (i / 10)
		{
			number[rank] = i % 10 + 48;
			rank--;
			i /= 10;
		}
		number[rank] = i % 10 + 48;
	}
	return (number);
}
