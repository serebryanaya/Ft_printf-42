#include "ft_printf.h"

char	*trans_u2(unsigned int copy, t_list *in, char *res, int i)
{
	while (copy != 0)
	{
		if (copy % 16 < 16 && in->type == 'X')
		{
			if (copy % 16 >= 10)
				res[i] = (copy % 16) + 55;
			else
				res[i] = (copy % 16) + 48;
		}
		if (copy % 16 < 16 && in->type == 'x')
		{
			if (copy % 16 >= 10)
				res[i] = (copy % 16) + 87;
			else
				res[i] = (copy % 16) + 48;
		}
		i--;
		copy = copy / 16;
	}
	return (res);
}

char	*trans_u(unsigned int copy, t_list *in)
{
	char	*res;
	int		i;

	i = count_num(copy);
	if (copy == 0)
		return (ft_strdup("0"));
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	res[i--] = '\0';
	res = trans_u2(copy, in, res, i);
	return (res);
}

void	init_info_hex(t_list *in, int *len, char *number)
{
	if (*number == '0' && in->flag == 1 && in->prec == 0)
		*len = 0;
	if (in->prec < 0)
	{
		in->prec *= -1;
	}
	if (in->width < 0)
	{
		in->minus = 1;
		in->width *= -1;
	}
	if (in->prec < *len)
		in->prec = *len;
	in->width -= in->prec;
	if (in->flag == 1)
		in->zero = 0;
}

void	is_hex2(t_list *in, char *str, int len, int i)
{
	while (str[i] != '\0' && len > 0)
	{
		in->count += write(1, &str[i], 1);
		i++;
	}
	while (in->width > 0)
	{
		space_or_nul_print(in, 0, 1, 1);
		in->width--;
	}
}

void	is_hex1(t_list *in, va_list arg, int i)
{
	unsigned int	num;
	char			*str;
	int				len;

	num = va_arg(arg, unsigned int) + 4294967295 + 1;
	str = trans_u(num, in);
	len = ft_strlen(str);
	init_info_hex(in, &len, str);
	while (in->minus == 0 && in->width > 0)
	{
		if (in->zero == 1)
			space_or_nul_print(in, 0, 1, 0);
		else
			space_or_nul_print(in, 0, 1, 1);
		in->width--;
	}
	if (in->prec > 0)
		space_or_nul_print(in, 0, in->prec - len, 0);
	is_hex2(in, str, len, i);
	if (str)
		free(str);
}
