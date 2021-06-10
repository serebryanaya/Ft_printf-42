#include "ft_printf.h"
#include <stdio.h> // FIXME!

int main(void)
{
    int my_ret_val;
    //int orig_ret_val;

    my_ret_val = ft_printf("hello,% world!", 23, 24, 4, 5, 7);
    printf("main: %d\n", my_ret_val);
    printf("%%\n");
    return (0);
}
/*
проверки:
просто %
*/