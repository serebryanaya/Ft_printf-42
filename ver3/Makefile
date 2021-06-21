NAME = libftprintf.a

SRCS = get_next_line.c get_next_line_utils.c // ENTER C-files!!!!!!!!!

OBJS = $(SRCS:.c=.o)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

.c.o:	libftprintf.h
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

RM	= rm -f
			
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
