# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smackere <smackere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 15:25:40 by smackere          #+#    #+#              #
#    Updated: 2022/01/10 21:13:23 by smackere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS = ft_hexademical.c ft_putnbr.c ft_printf.c
    
HEADER	= ft_printf.h 
  
OBJS	= $(patsubst %.c, %.o, $(SRCS))

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEADER)



all		:   $(NAME)

$(NAME)	:  $(OBJS) Makefile
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJS)

fclean	:   clean
	$(RM) $(NAME)

re		:    fclean all

.PHONY	:   all clean fclean re