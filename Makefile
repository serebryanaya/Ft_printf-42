NAME = libftprintf.a

SRCS = ft_printf.c standart_func1.c standart_func2.c print_int.c print_str.c \
print_hex.c print_pointer.c print_char.c print_uns.c parce_format.c init_clean.c \
standart_func3.c

SRCS_BONUS = ft_printf_bonus.c standart_func1_bonus.c standart_func2_bonus.c \
print_int_bonus.c print_str_bonus.c print_hex_bonus.c print_pointer_bonus.c \
print_char_bonus.c print_uns_bonus.c parce_format_bonus.c init_clean_bonus.c \
standart_func3_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) ft_printf.h
		ar rc $(NAME) $(OBJS)

bonus:	all $(OBJS_BONUS) ft_printf_bonus.h
		ar rc $(NAME) $(OBJS_BONUS)

RM	= rm -f
			
clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
