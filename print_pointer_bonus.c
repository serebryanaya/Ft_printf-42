#include "ft_printf_bonus.h"

void	init_info_pointer(t_list *in)
{
	if (in->prec < 0)
	{
		in->minus = 1;
		in->width = -(in->prec);
		in->flag = 0;
		in->prec = 0;
	}
	if (in->width < 0)
	{
		in->minus = 1;
		in->width = -(in->width);
	}
	if (in->flag == 1)
		in->zero = 0;
}

void	is_pointer1(va_list arg, t_list *in, int i, int rank)
{
	char				number[18];
	unsigned long long	num;
	unsigned long long	copy;

	num = va_arg(arg, unsigned long long);
	while (i < 18)
		number[i++] = '\0';
	copy = num;
	while (num != 0)
	{
		num = num / 16;
		rank++;
	}
	is_pointer2(copy, in, rank, number);
}

void	is_pointer2(unsigned long long copy, t_list *in, int rank, char *number)
{
	int	len;

	while (copy != 0)
	{
		if (copy % 16 < 16)
		{
			if (copy % 16 >= 10)
				number[rank - 1] = (copy % 16) + 87;
			else
				number[rank - 1] = (copy % 16) + 48;
		}
		rank--;
		copy = copy / 16;
	}
	if ((*number == 0 && in->prec == 0) || (number == NULL && in->flag == 1))
		len = 2;
	else
		len = ft_strlen(number) + 2;
	init_info_pointer(in);
	if ((number[0] == 0 && !(in->flag == 1)) || \
			(number == NULL && in->flag == 0))
		len = 3;
	is_pointer3(in, number, &len);
}

void	is_pointer3(t_list *in, char *number, int *len)
{
	int	i;

	i = 0;
	if (in->zero == 1 && (in->width >= *len || in->width >= in->prec))
		in->prec = in->width;
	if (in->prec < *len)
		in->prec = *len;
	if (len >= 0 && in->minus == 0)
		space_or_nul_print(in, 0, in->width - in->prec, 1);
	in->count += write(1, "0x", 2);
	if (in->prec > *len)
		space_or_nul_print(in, 0, in->prec - *len + 2, 0);
	if (*number == 0 && in->flag == 0)
		in->count += write(1, "0", 1);
	while (number[i] != '\0')
	{
		if (*number != '0')
			in->count += write(1, &number[i], 1);
		i++;
	}
	if (in->width > in->prec && in->minus == 1)
		space_or_nul_print(in, 0, in->width - in->prec, 1);
}
