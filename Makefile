# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 17:56:04 by jeulliot          #+#    #+#              #
#    Updated: 2022/04/19 00:17:44 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= main.c \
				src/ft_check_arg.c src/ft_utils_push_swap.c \
				src/ft_fct_push.c src/ft_fct_rotate.c \
				src/ft_fct_reverse_rotate.c src/ft_fct_swap.c \
				src/ft_sort.c src/ft_sort_utils.c \
				src/ft_order_tabs_a.c src/ft_order_tabs_b.c\
				src/ft_search.c \
				src/ft_first_sort_utils.c
				
SRCS_BONUS		= bonus/ft_checker.c \
				bonus/ft_check_arg_bonus.c \
				bonus/ft_utils_bonus.c \
				bonus/get_next_line.c \
				bonus/get_next_line_utils.c \
				bonus/operations/ft_fct_swap.c \
				bonus/operations/ft_fct_push.c \
				bonus/operations/ft_fct_rotate.c \
				bonus/operations/ft_fct_reverse_rotate.c \

OBJS			= ${SRCS:.c=.o}
OBJS_BONUS		= ${SRCS_BONUS:.c=.o}
LIBFT			= make -C libft/
NAME			= push_swap
NAME_BONUS		= checker
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
LDFLAGS			= -I./include/ -I./libft/

${NAME}:		${OBJS}
				${LIBFT}
				$(CC) -o ${NAME} ${OBJS} libft/libft.a

${NAME_BONUS}:	${OBJS_BONUS}
				$(CC) -o ${NAME_BONUS} ${OBJS_BONUS} libft/libft.a

all:			${NAME}
	
bonus:			${NAME} ${NAME_BONUS}

clean:			
				${RM} ${OBJS}

cleanb:
				${RM} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME}
				@make fclean -C libft/

fcleanb:		cleanb
				${RM} ${NAME_BONUS}
				@make fclean -C libft/
	
re:				fclean all

rebonus:		fclean fcleanb all bonus
	
.PHONY:			all clean fclean re bonus fclean rebonus
