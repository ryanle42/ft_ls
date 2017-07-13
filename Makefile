# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 18:47:59 by rle               #+#    #+#              #
#    Updated: 2017/05/27 17:46:58 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

OBJS = $(addprefix ./srcs/, \
			$(addsuffix .o, \
				$(addprefix names/, \
					names_init \
					add_name \
					sort_add_name \
				) \
				$(addprefix sort/, \
					is_sorted \
					sort_names \
				) \
				$(addprefix ent/, \
					ent_init \
					read_ent \
					add_ent \
				) \
				$(addprefix print/, \
					print_singent \
					print_entlst \
					print_errlst \
					print_ents \
					print_helpers \
					print_l \
					print_names \
				) \
				$(addprefix get/, \
					get_commands \
					get_sperm \
				) \
				$(addprefix init/, \
					entlst_init \
				) \
				$(addprefix error/, \
					errors_init \
					nofile \
					pdeny \
					errlst_init \
				) \
				main \
				entlst \
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
