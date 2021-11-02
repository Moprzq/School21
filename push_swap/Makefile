SRCS		= push_swap.c push_swap_addfunc.c push_swap_validation.c push_swap_sort.c push_swap_sort_2.c push_swap_sort_3.c push_swap_operations_1.c push_swap_operations_2.c push_swap_operations_3.c push_swap_create_stack.c push_swap_find_middle.c

NAME		= push_swap

CC			= gcc

RM			= rm -f

INC			= ./

HEAD		= ./push_swap.h

CFLAGS		= -Wall -Wextra -Werror

OBJS		= ${SRCS:.c=.o}

%.o:		%.c ${HEAD}
			${CC} ${CFLAGS} -c $< -o $@ -I ${INC}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all, clean, fclean, re
