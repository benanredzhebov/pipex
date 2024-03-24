# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 10:18:55 by beredzhe          #+#    #+#              #
#    Updated: 2024/03/10 08:44:45 by beredzhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

SRCS 	= srcs/pipex.c srcs/utils.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

HEADER	= -Iincludes

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror

.c.o:		%.o : %.c
					@gcc ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${NAME}

${NAME}:	${OBJS}
					@echo "\033[33m----Compiling Libft---"
					@make re -C ./lib/libft
					@$(CC) ${OBJS} -Llib/libft -lft -o ${NAME}
					@echo "\033[32mProject successfully compiled!\033[0m\n"

clean:
					@make clean -C ./lib/libft
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C ./lib/libft
					@rm -f $(NAME)
					@rm -f ${NAME}
					@echo "\n\033[31mDeleted EVERYTHING!\033[0m\n"

re:			fclean all

.PHONY: all clean fclean re