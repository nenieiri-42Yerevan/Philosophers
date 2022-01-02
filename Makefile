NAME		= philo

SRCS		= $(wildcard ./srcs/*.c)

OBJS		= $(patsubst %.c, %.o, $(SRCS))

CC			= gcc

CFLAGS		=-Wall -Wextra -Werror

RM			= rm -rf

.PHONY:		all clean fclean re

%.o:		%.c ./srcs/philo.h
			@$(CC) $(CFLAGS) -pthread -o $@ -c $<

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -pthread -o $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
