#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
    int     width;
    int     zero;
    int     minus;
    char    type;
    int     precision;
    int     star;
}           t_list;

int ft_printf(const char *, ...);

#endif