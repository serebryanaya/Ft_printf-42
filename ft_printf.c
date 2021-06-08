#include "ft_printf.h"
#include <stdio.h> // FIXME!

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
    return (1);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
    size_t  len;
    size_t i;

	if (!s1)
        return (NULL);
    i = 0;
    len = ft_strlen(s1);
    dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (s1[i] != '\0')
    {
        dup[i] = s1[i];
        i++;
    }
    dup[i] = '\0';
	return (dup);
}
/*
t_list  init(void)
{
    t_list  info;

    info.width = 0;
    info.zero = 0;
    info.minus = 0;
    info.type = '\0';
    info.precision = -1; // WHY???????????????
    info.star = 0;
    return (info);
}*/

int search_type(char c, t_list *info)
{
        if (c == 'c' || c == 's' || c == 'p' || c == 'd' || \
        c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
            {
                (*info)->type = 1;
                return (1)
            }
        return (0);
}

int check_precision(str, i, info, argptr)
{
if (str[i] == '*')
{
    (*info)->precision = va_arg(argptr, int);
    i++;
}
else
{
    (*info)->precision = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
    (*info)->precision = ((*info)->precision * 10) + (str[i] - '0');
    i++;
    }
}
return (i);
}

t_list  width_with_arg(t_list *info, va_list argptr)
{
    (*info)->star = 1;
    (*info)->wigth = va_arg(argptr, int);
    if ((*info)->width < 0)
        {
            (*info)->minus = 1;
            (*info)->width = -((*info)->width);
        }
    return (info);
}


int flag_search(const char *str, int i, t_list *info, va_list argptr)
{
    while (str[i] != '\0')
    {
       // if (str[i] < '0' || str[i] > '9')
       if (str[i] == '0' && (*info)->minus == 0)
        (*info)->zero == 1;
        if (str[i] == '.')
            check_precision(str, (i + 1), info, argptr);
        if (str[i] == '-')
        {
            (*info)->minus == 1;
            (*info)->zero == 0;
        }
        if (str[i] == '*')
            width_with_arg(info, argptr);
        if (str[i] >= '0' && str[i] <= '9')
        {
            if ((*info)->star == 1);
                (*info)->width == 0;
            (*info)->width = (*info)->width * 10) + (str[i] - '0');
        }
        if ((search_type(str[i], info)) == 1)
            break ;
        i++;
    }
    return (i);    
}

int type_search(t_list *info, va_list argptr)
{
    int counter;

    counter = 0;
    return (counter);    
}

int check_format(va_list argptr, char *str, t_list *info)
{
    int counter;
    int i;

    i = 0;
    counter = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '%')
            counter += ft_putchar_fd(str[i], 1);
        else if (str[i] == '%' && str[i + 1] != '\0')
        {
            i++;
            i = flag_search(str, i, info, argptr);
            if (str[i] == '-' || str[i] == '0' || str[i] == '.' || str[i] == '*')
                counter += 1;
                //counter += type_search(info, argptr);
            else if (str[i] != '\0')
                counter += ft_putchar_fd(str[i], 1);        
        }
    i++;
    printf("check va: %p\n", argptr); //FIXME!
    //printf("check info: %p\n", *info); //FIXME!
    }
    info->zero = 1;
    return (counter);
}

int ft_printf(const char *format, ...)
{
 int counter;
 char *str;
 va_list argptr;
 t_list info;

    counter = 0;
    str = ft_strdup(format);
    info.width = 0;
    info.zero = 0;
    info.minus = 0;
    info.type = '\0';
    info.precision = -1; // WHY???????????????
    info.star = 0;
printf("check info: %d\n", info.precision); //FIXME!
printf("check dup: %s\n", str); //FIXME!
va_start(argptr, format);
printf("check format: %p\n", format); //FIXME!
printf("check va: %p\n", argptr); //FIXME!
counter = check_format(argptr, str, &info);
va_end(argptr);
free(str);
return (counter);   
}