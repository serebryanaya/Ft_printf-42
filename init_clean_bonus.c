#include "ft_printf_bonus.h"

void	init(t_list *in)
{
	in->width = 0;
	in->zero = 0;
	in->minus = 0;
	in->type = '\0';
	in->prec = 0;
	in->flag = 0;
	in->ind = 0;
	in->count = 0;
	in->sign = 1;
	in->sp = 0;
	in->star = 0;
}

void	clear(t_list *in)
{
	in->width = 0;
	in->zero = 0;
	in->minus = 0;
	in->type = '\0';
	in->prec = 0;
	in->flag = 0;
	in->sign = 1;
	in->sp = 0;
	in->star = 0;
}
