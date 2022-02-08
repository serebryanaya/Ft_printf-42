#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	int		zero;
	int		minus;
	int		prec;
	int		flag;
	int		width;
	int		sign;
	int		sp;
	char	type;
	int		count;
	int		ind;
	int		star;
}			t_list;

int			ft_printf(const char *format, ...);
int			base_func(va_list arg, const char *str, t_list *in);
char		*base_func2(va_list arg, const char *s, t_list *in, int *i_f);
int			distrib_out(va_list arg, t_list *in);
int			digit_from_str(char *str, int *i, va_list arg, t_list *in);
int			check_format1(va_list arg, t_list *in, char *str, int i);
int			check_format2(va_list arg, t_list *in, char *str, int i);
int			check_format3(va_list arg, t_list *in, char *str, int i);
int			check_format4(t_list *in, va_list arg);
int			ft_atoi_mod(char *s, int i, int sign, t_list *in);
void		init_info_char(t_list *in, int *len);
void		is_char(va_list arg, t_list *in);
void		init_info_str(t_list *in, int *len);
void		is_string(va_list arg, t_list *in, int len, int i);
void		init_info_int(t_list *in, int *len, char *number);
void		is_int1(va_list arg, t_list *in);
void		is_int2(t_list *in, char *number, int *len, int i);
void		is_int3(t_list *in, char *number, int *len, int i);
void		space_or_nul_print(t_list *in, int i, int len, int flag);
void		is_unsigned1(va_list arg, t_list *in);
void		is_unsigned2(t_list *in, char *number, int len);
char		*ft_u_itoa_mod1(unsigned int n, int rank, t_list *in);
char		*ft_uns_itoa_mod2(unsigned int n, int rank, char *num, t_list *in);
void		init_info_pointer(t_list *in);
void		is_pointer1(va_list arg, t_list *in, int i, int rank);
void		is_pointer2(unsigned long long copy, t_list *in, int rank, char *n);
void		is_pointer3(t_list *in, char *number, int *len);
void		init_info_hex(t_list *in, int *len, char *number);
void		is_hex1(t_list *in, va_list arg, int i);
void		is_hex2(t_list *in, char *str, int len, int i);
void		is_hex4(t_list *in, char *number, int i);
int			ft_strlen(char *s);
char		*ft_itoa_mod1(int integer, int rank, t_list *in);
char		*ft_itoa_mod2(int integer, int rank, char *num, t_list *in);
void		*ft_calloc(int count, int size);
int			ft_isalpha(int c);
char		*ft_substr (char const *str, int start, int len, int	i);
int			ft_strlcpy(char *dst, char *src, int dstsize);
char		*ft_strdup(char *str);
int			count_num(unsigned int num);
int			ft_isdigit(int c);
void		init(t_list *in);
void		clear(t_list *in);

#endif
