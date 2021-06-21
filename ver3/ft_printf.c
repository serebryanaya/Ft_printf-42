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
    printf("\n"); //FIXME!
    return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
    int	len;

    if (!s)
        return (0);
    len = ft_strlen(s);
    write(fd, s, len);
    printf("putstr finish<<<<\n"); //FIXME!
    return (len);
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


/*
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
 */

void init (t_list *info)
{
    info->width = 0;
    info->zero = 0;
    info->minus = 0;
    info->type = '\0';
    info->precision = -1; // если не задана, то она отсутствует
    info->asterisk = 0;
    info->len = 0;
    info->counter = 0;
}

/*int error_exit(void) //really need?
{
    return (-1);
}*/

int flag_parce(va_list arg, const char *str, int start, t_list *info)
{

    printf(">>247>>info->len = %d\n", info->len); // FIXME!
    printf(">>247>>start = %d\n", start); // FIXME!
    printf(">>247>>str[start] = %c\n", str[start]); // FIXME!
    while (info->len > start)
    {
        if (str[start] == '-')
        {
            info->minus = 1;
            info->zero = 0;
        }
        if (str[start] == '0')
        {
            if (info->minus != 1)
                info->zero = 1;
        }
        if (str[start] > '0' && str[start] <= '9') // find width
        {
            while (str[start] >= '0' && str[start] <= '9') {
                info->width = 10 * info->width + (str[start] - '0');
                printf(">>247>>info->width = %d\n", info->width); // FIXME!
                start++;
            }
            if (str[start] != '.') // find precision
            {
                start++;
                while (str[start] >= '0' && str[start] <= '9') {
                    info->precision = 10 * info->precision + (str[start] - '0');
                    start++;
                }
            }
            if (str[start] == '*') {
                if (str[start - 1] == '-')
                    info->precision = va_arg(arg, int);
                else
                info->width = va_arg(arg, int);
            }
            else
                return (-1);
        }
            start++;
    }
    return (0);
}

int distrib_out(va_list arg, t_list *info)
{
    int counter;
    counter = 0;
    return (counter);
}



//type parce

int ft_printf(const char *format, ...)
{
    va_list arg;
    t_list  info;

    va_start(arg, format);
    init(&info);

     while (format[info.len] != '\0')
     {
         //printf(">>279>>str[i], i = %c [%d]\n", str[i], i); // FIXME!
         /*if (format[info.len] == '%' && format[info.len + 1] == '\0')
             return(-1);*/
         if (format[info.len] != '%')
         {
             while (format[info.len] != '%' && format[info.len] != '0')
             {
                 info.counter += ft_putchar_fd(format[info.len], 1);
                 info.len++;
             }
         }
         //type_parce(arg, format, &info);

        //printf(">>289>>i = %d\n", i); // FIXME!
        //printf(">>289>>info.len = %d\n", info.len); // FIXME!
        //i++;
        //printf(">>286>>str + info.len = %s\n", str + info.len); // FIXME!

    //printf(">>290>>counter2 = %d\n", counter2); // FIXME!
    //printf(">>291>>str + i = %s\n", str + i); // FIXME!

    //i += 2;
    //info.len += 2;
   /* printf(">>301>>zero = %d\n", info.zero); // FIXME!
         printf(">>301>>minus = %d\n", info.minus); // FIXME!
         printf(">>301>>precision = %d\n", info.precision); // FIXME!
         printf(">>301>>asterisk = %d\n", info.asterisk); // FIXME!
         printf(">>301>>width = %d\n", info.width); // FIXME!
         printf(">>301>>type = %c\n", info.type); // FIXME!
         printf(">>301>>len = %d\n", info.len); // FIXME!*/
    }
    va_end(arg);
    printf("\n>>301>>len end = %d\n", info.len); // FIXME!
    //free(str);
    return (info.counter);
}