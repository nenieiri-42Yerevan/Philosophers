NAME		= philo

SRCS		= $(wildcard ./srcs/*.c)

OBJS		= $(patsubst %.c, %.o, $(SRCS))

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I ./includes

RM			= rm -rf

.PHONY:		all clean fclean re

%.o:		%.c ./includes/philo.h
			@$(CC) $(CFLAGS) $(INCLUDES) -pthread -o $@ -c $<

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -pthread -o $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
