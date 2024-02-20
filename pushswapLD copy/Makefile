SRCS = main.c ft_check_args.c ft_initstack.c \
libft_utils.c ordenar.c swap.c push.c \
rotate.c reverse.c chunks_ord.c cost.c \
movements.c free.c
#SRCSBONUS = bonus/main.c bonus/check_args.c bonus/inits.c \
bonus/libft_utils.c bonus/movements.c \
bonus/sort_utils.c \
includes/get_next_line/get_next_line.c \
includes/get_next_line/get_next_line_utils.c \
bonus/checker.c
#
OBJS = ${SRCS:.c=.o}
#OBJSBONUS = ${SRCSBONUS:.c=.o}

NAME = push_swap
#NAME_BONUS = checker
INCLUDE = push_swap.h
#INCLUDE_BONUS = includes/get_next_line/get_next_line.h

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g


# Implicit method
%.o:%.c $(INCLUDE) Makefile
			$(CC) $(CFLAGS) -c $< -o $@


# My methods
all: 		${NAME}

${NAME}:	${OBJS} ${INCLUDE}
			gcc  $(CFLAGS) ${OBJS} -o ${NAME} 

${NAME_BONUS}:	${OBJS}
			gcc  $(CFLAGS) -o

#bonus:		 ${NAME_BONUS}
#			@touch bonus

clean: 		
			${RM} ${OBJS}
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}
			${RM} 

re:			fclean all

.PHONY: all clean fclean re bonus
