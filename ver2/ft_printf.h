#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
    int	zero;
    int	minus;
    int precision;
    int	asterisk;
    int width;
    char type;
    int len; // index, where is %
}           t_list;

int ft_printf(const char *, ...);

#endif