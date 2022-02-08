#include "ft_printf_bonus.h"

int	check_format1(va_list arg, t_list *in, char *str, int i)
{
	while (str[i] != '\0' && ft_isalpha(str[i]) != 1 && \
			str[i] != '%' && str[i] != '.')
	{
		if (str[i] == '0' && in->minus == 0)
		{
			in->zero = 1;
			i++;
		}
		if (str[i] == '-')
		{
			in->minus = 1;
			in->zero = 0;
		}
		if (str[i] == ' ')
			in->sp = 1;
		if (check_format2(arg, in, str, i) == -1)
			break ;
		i++;
	}
	return (check_format3(arg, in, str, 0));
}

int	check_format2(va_list arg, t_list *in, char *str, int i)
{
	if (str[i] == '*' && str[i - 1] != '.')
	{
		in->width = digit_from_str(str, &i, arg, in);
		return (-1);
	}
	else if ((str[i] >= '1' && str[i] <= '9') && str[i - 1] != '.')
	{
		in->width = digit_from_str(str, &i, arg, in);
		return (-1);
	}
	return (0);
}

int	check_format3(va_list arg, t_list *in, char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			in->flag = 1;
			i++;
			if (ft_isdigit(str[i]) == 1 || str[i] == '*')
			{
				if (str[i] == 0 && i == 0)
					break ;
				in->prec = digit_from_str(str, &i, arg, in);
				if (in->prec < 0 && (in->type == 'c' || in->type == '%'))
					in->prec = 0;
			}
			else
				in->prec = 0;
		}
		if (ft_isalpha(str[i]) == 1 || str[i] == '%')
			return (check_format4(in, arg));
		i++;
	}
	return (check_format4(in, arg));
}

int	check_format4(t_list *in, va_list arg)
{
	if (in->flag == 1)
		in->zero = 0;
	if (distrib_out(arg, in) == -1)
		return (-1);
	return (0);
}
