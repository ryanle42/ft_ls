# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 18:47:59 by rle               #+#    #+#              #
#    Updated: 2017/05/23 21:03:56 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

OBJS = $(addprefix ./srcs/, \
			$(addsuffix .o, \
				main \
				get_commands \
				error \
				ent \
				entlst \
				get_sperm \
				helpers \
				recursion \
			) \
		)

CFLAGS = -Wall -Werror -Wextra

CC = @gcc

INCLUDES = -I ./includes -I ./libft/includes

LIB = libft

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)/libft.a $(INCLUDES) -o $(NAME)
	@echo "\x1B[31mFT_LS made"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIB): force
	@make -C $(LIB)

force: 
	@true

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIB)
	@echo "\x1B[34m~~~clean~~~"

fclean: clean
	@rm -f $(NAME)

re: fclean all
