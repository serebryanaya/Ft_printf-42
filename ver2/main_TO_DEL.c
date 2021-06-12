#include "ft_printf.h"
#include <stdio.h> // FIXME!

int main(void)
{
    int my_ret_val;
    //int orig_ret_val;

    my_ret_val = ft_printf("0hello,%1d1world!%c", 23, 24, 4, 5, 7);
    printf(">>>>return: %d\n", my_ret_val);
    //printf("%%\n"); //здесь тестим всякую дичь
    
    //while (1);
    return (0);
}

/*
проверки:
просто %
*/


