#include "ft_printf_bonus.h"

void	init_info_int(t_list *in, int *len, char *number)
{
	if ((*number == '0') && in->flag == 1)
		*len = 0;
	if (in->width < 0 || (in->prec < 0 && in->star == 0))
		in->minus = 1;
	if (in->width < 0)
		in->width *= -1;
	if (in->prec < 0 && in->star == 0)
		in->prec *= -1;
	in->prec -= *len;
	if (in->prec > 0)
		in->width = in->width - in->prec - *len;
	else
		in->width = in->width - *len;
	if (in->sign < 0)
		in->width = in->width - 1;
	if (in->flag == 1 && in->star == 0)
		in->zero = 0;
}

void	is_int1(va_list arg, t_list *in)
{
	int		num;
	char	*number;
	int		len;

	num = va_arg(arg, int);
	if (num < 0)
		in->sign = -1;
	number = ft_itoa_mod1(num, 1, in);
	if (number == NULL)
	{
		in->count = -1;
		len = 0;
		init_info_int(in, &len, number);
		is_int2(in, number, &len, 0);
		return ;
	}
	len = ft_strlen(number);
	if (num < 0)
		len--;
	init_info_int(in, &len, number);
	is_int2(in, number, &len, 0);
	if (number != NULL)
		free(number);
}

void	is_int2(t_list *in, char *number, int *len, int i)
{
	if (in->sign < 0 && in->zero == 1)
	{
		in->count += write(1, "-", 1);
		i++;
	}
	while (in->minus == 0 && in->width-- > 0)
	{
		if (in->zero == 1)
			space_or_nul_print(in, 0, 1, 0);
		else
			space_or_nul_print(in, 0, 1, 1);
	}
	if (in->sign < 0 && in->prec > 0)
	{
		in->count += write(1, "-", 1);
		i++;
	}
	while (in->prec-- > 0)
		space_or_nul_print(in, 0, 1, 0);
	if (*number == '0' && in->flag == 0)
		in->count += write(1, &number[0], 1);
	is_int3(in, number, len, i);
}

void	is_int3(t_list *in, char *number, int *len, int i)
{
	while (number[i] != '\0')
	{
		if (*number != '0' && len > 0)
			in->count += write(1, &number[i], 1);
		i++;
	}
	while (in->width-- > 0)
		space_or_nul_print(in, 0, 1, 1);
}
