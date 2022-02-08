#include "ft_printf_bonus.h"

void	init_info_char(t_list *in, int *len)
{
	if (in->width < 0)
	{
		in->width *= -1;
		in->minus = 1;
	}
	if (in->prec < 0)
	{
		in->prec *= -1;
		in->width = in->prec;
		in->minus = 1;
	}
	if (in->minus == 1)
		in->zero = 0;
	if (in->prec > 0 && in->prec < *len)
		*len = in->prec;
	in->prec = 1;
	in->flag = 1;
}

void	is_char(va_list arg, t_list *in)
{
	char	c;
	int		len;

	len = 0;
	if (in->type == '%')
		c = '%';
	else
		c = va_arg(arg, int);
	init_info_char(in, &len);
	if (in->minus == 1 || in->width < 2)
		in->count += write(1, &c, 1);
	while ((len < in->width - 1 && in->width > 0) || \
			(in->flag == 1 && len + 1 < in->prec))
	{
		if (in->zero == 1)
			in->count += write(1, "0", 1);
		else
			in->count += write(1, " ", 1);
		len++;
	}
	if (in->minus != 1 && len <= in->width && len > 0)
		in->count += write(1, &c, 1);
	else if (in->minus == 1 && len < in->width - 1 && in->width > 0)
		in->count += write(1, " ", 1);
}
