NAME = fractol
CC = cc -Wall -Wextra -Werror
FLAG = -lmlx -framework OpenGl -framework AppKit
SRCS = hook.c main.c subfunc.c arg_check.c draw_fractol.c my_fractol.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) $^ -o $@

%.o : %.c fractol.h
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)

re:
	@make fclean
	@make all

.PHONY : clean fclean all re
