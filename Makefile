# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile1                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-monc <fde-monc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/19 13:46:47 by fde-monc          #+#    #+#              #
#    Updated: 2016/09/19 15:44:33 by fde-monc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CURS = -ltermcap

PATH_SRC = src/

SRC =	commands.c \
		cursor_motion.c \
		error.c \
		exit.c \
		get_files.c \
		get_infos.c \
		hasnonext.c \
		misc.c \
		prints.c \
		run.c \
		signal.c \
		slect.c

SRC_FILE = $(addprefix $(PATH_SRC), $(SRC));

OBJECTS = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

LIB = libft

LIB_EXE = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIB_EXE)
	 $(CC) $(CURS) $(CFLAGS) -Iinc/ -L$(LIB) -lft $(OBJECTS) -o $(NAME)

$(LIB_EXE) :
	make -C $(LIB) nclean

$(OBJECTS) : %.o : %.c
	$(CC) $(CFLAGS) -Iinc/ -c $< -o $@

clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)

re : fclean $(NAME)

nclean : all clean
