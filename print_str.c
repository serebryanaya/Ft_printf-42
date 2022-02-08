#include "ft_printf.h"

void	init_info_str(t_list *in, int *len)
{
	if (in->width < 0)
	{
		in->width *= -1;
		in->minus = 1;
	}
	if (in->prec < 0 && in->star == 0)
	{
		in->minus = 1;
		if (in->width < -in->prec)
			in->width = -in->prec;
		in->prec = *len;
	}
	if (in->minus == 1)
		in->zero = 0;
	if (in->prec > 0 && in->prec < *len)
		*len = in->prec;
}

void	is_string(va_list arg, t_list *in, int len, int i)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	init_info_str(in, &len);
	if (str[0] == '\0')
		len = 0;
	if ((in->prec < len || len == 0) && str && str[0] != '\0' && in->flag == 1)
		len = in->prec;
	if (in->width > len && in->minus == 0)
	{
		if (in->zero == 1)
			space_or_nul_print(in, 0, in->width - len, 0);
		else
			space_or_nul_print(in, 0, in->width - len, 1);
	}
	while (str[i] != '\0' && i < len)
		in->count += write(1, &str[i++], 1);
	if (in->width > len && in->minus == 1)
		space_or_nul_print(in, 0, in->width - len, 1);
}
