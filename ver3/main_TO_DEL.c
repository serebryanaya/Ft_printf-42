#include "ft_printf.h"
#include <stdio.h> // FIXME!

int main(void)
{
    int my_ret_val;
    //int orig_ret_val;

    my_ret_val = ft_printf("0hello,%", 23, 24);
    printf(">>>>return: %d\n", my_ret_val);
    //printf("%%\n"); //здесь тестим всякую дичь
    
    //while (1);
    return (0);
}

/*
проверки:
просто %
*/

int type_parce(va_list arg, const char *str, t_list *info)
{
    //int counter;

    int start;

    //counter = 0;

    start = ++info->len;
    //printf(">>228>>str = %s\n", str); // FIXME!
    while (str[info->len] != 'c' && str[info->len] != 's' && str[info->len] != 'd' && \
    str[info->len] != 'i' && str[info->len] != 'u' && str[info->len] != 'x' && \
    str[info->len] != 'X')
    {
        info->len++;
        if (str[info->len] == '\0')
            return (-1);
    }
    info->type = str[info->len]; // написать про -1 при непопадании
    //printf(">>237>>info->type = %c\n", info->type); // FIXME!
    //printf(">>237>>info->len = %d\n", info->len); // FIXME!
    //printf(">>298>>str = %s\n", str); // FIXME!
    //printf(">>237>>start = %d\n", start); // FIXME!
    //printf(">>237>>info->len = %d\n", info->len); // FIXME!


    /*if (info->len != start)
        if (flag_parce(arg, str, start, info) < 0)
            return (-1);
    if (distrib_out(arg, info) < 0)
        return (-1);
        */

    //printf(">>241>>counter = %d\n", counter); // FIXME!
    return (0);
}

