# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle <rle@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 09:03:31 by rle               #+#    #+#              #
#    Updated: 2017/05/26 18:39:28 by rle              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ =	$(addprefix ./srcs/, \
			$(addprefix libft/, \
				$(addsuffix .o, \
					ft_memset \
					ft_bzero \
					ft_memcpy \
					ft_memccpy \
					ft_memmove \
					ft_memchr \
					ft_memcmp \
					ft_strlen \
					ft_strdup \
					ft_strncpy \
					ft_strcpy \
					ft_strcat \
					ft_strncat \
					ft_strlcat \
					ft_strchr \
					ft_strrchr \
					ft_strstr \
					ft_strnstr \
					ft_strcmp \
					ft_strncmp \
					ft_atoi \
					ft_isalpha \
					ft_isdigit \
					ft_isalnum \
					ft_isascii \
					ft_isprint \
					ft_toupper \
					ft_tolower \
					ft_memalloc \
					ft_memdel \
					ft_strnew \
					ft_strdel \
					ft_strclr \
					ft_striter \
					ft_striteri \
					ft_strmap \
					ft_strmapi \
					ft_strequ \
					ft_strnequ \
					ft_strsub \
					ft_strjoin \
					ft_strtrim \
					ft_strtrim \
					ft_strsplit \
					ft_strswap \
					ft_itoa \
					ft_putchar \
					ft_putstr \
					ft_putendl \
					ft_putnbr \
					ft_putchar_fd \
					ft_putstr_fd \
					ft_putendl_fd \
					ft_putnbr_fd \
					ft_strrev \
					ft_lstnew \
					ft_lstdelone \
					ft_lstadd \
					ft_lstdel \
					ft_lstiter \
					ft_lstmap \
					ft_wd_len \
					ft_count_wds \
					ft_int_length \
					ft_strn_append \
					ft_copystr \
					ft_realloc \
					get_next_line \
				) \
			) \
			$(addprefix ft_printf/, \
				$(addsuffix .o, \
					ft_printf \
					flags \
					params \
					size_converters \
					write_hex \
					hex_helpers \
					write_int \
					int_helpers \
					write_octal \
					octal_helpers \
					write_unsigned_int \
					unsigned_helpers \
					write_ptr \
					write_char \
					write_string \
				) \
			) \
		)


CC = @gcc -Wall -Werror -Wextra -I ./includes

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@ar rc $(NAME) $(OBJ)
	@echo "\x1B[33mLibrary made"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: clean all
