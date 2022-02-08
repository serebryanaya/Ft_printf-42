#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_list	in;

	va_start(arg, format);
	init(&in);
	if (base_func(arg, format, &in) == -1)
		in.count = -1;
	va_end(arg);
	return (in.count);
}

int	base_func(va_list arg, const char *str, t_list *in)
{
	char	*sub_format;
	int		i_f;

	while (str[in->ind] != '\0')
	{
		while (str[in->ind] != '%')
		{
			in->count += write(1, &str[in->ind], 1);
			(in->ind)++;
			if (str[in->ind] == '\0')
				return (0);
		}
		i_f = ++(in->ind);
		while (str[i_f] != '\0' && !ft_isalpha(str[i_f]) && str[i_f] != '%')
			i_f++;
		if (str[i_f] != '\0')
			in->type = str[i_f];
		sub_format = base_func2(arg, str, in, &i_f);
		if (sub_format != NULL)
			free(sub_format);
		in->ind = i_f + 1;
	}
	return (0);
}

char	*base_func2(va_list arg, const char *str, t_list *in, int *i_form)
{
	char	*sub_format;

	sub_format = ft_substr(str, in->ind, *i_form - in->ind + 1, 0);
	if (!sub_format)
		return (NULL);
	if (check_format1(arg, in, sub_format, 0) == -1)
		(*i_form)--;
	return (sub_format);
}

int	distrib_out(va_list arg, t_list *in)
{
	if (in->type == 'c' || in->type == '%')
		is_char(arg, in);
	else if (in->type == 's')
		is_string(arg, in, 1, 0);
	else if (in->type == 'd' || in->type == 'i')
		is_int1(arg, in);
	else if (in->type == 'u')
		is_unsigned1(arg, in);
	else if (in->type == 'x' || in->type == 'X')
		is_hex1(in, arg, 0);
	else if (in->type == 'p')
		is_pointer1(arg, in, 0, 0);
	else
		return (-1);
	clear(in);
	return (0);
}

int	digit_from_str(char *str, int *i, va_list arg, t_list *in)
{
	int	num;

	num = 0;
	if (str[*i] == '*')
	{
		num = va_arg(arg, int);
		in->star = 1;
		if (num < 0)
		{
			in->flag = 0;
			if (in->type == '%')
				num = 0;
		}
		return (num);
	}
	if (str[*i] != '*')
		num = ft_atoi_mod(str + *i, 0, 1, in);
	if (num < 0)
	{
		in->width = -num;
		in->minus = 1;
	}
	return (num);
}
