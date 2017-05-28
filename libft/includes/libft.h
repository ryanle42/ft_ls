/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:54:51 by rle               #+#    #+#             */
/*   Updated: 2017/05/27 18:53:31 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 10

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

/*
**	LIBFT STRUCTS
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_file
{
	int				file;
	int				ret;
	char			*extra;
	struct s_file	*next;
}					t_file;

/*
**	FT_PRINTF STRUCTS
*/

typedef struct		s_flags
{
	int				plus;
	int				minus;
	int				zero;
	int				hash;
	int				space;
}					t_flag;

typedef struct		s_parameters{
	t_flag			*flags;
	int				size;
	int				width;
	int				precision;
	int				is_precision;
	int				counter;
	int				zeros;
}					t_param;

/*
**	LIBRARY
*/

int					get_next_line(const int fd, char **line);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, \
					size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(const char *s1, const char *s2);
char				*ft_strncat(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2, int opt);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strswap(char **str1, char **str2);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strrev(char *str, int length);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_count_wds(char const *s, char c);
int					ft_wd_len(char const *s, char c, int j);
int					ft_int_length(intmax_t n);
char				*ft_strn_append(char *s1, char *s2, int n);
char				*ft_copystr(char *str);
char				*ft_realloc(char *str, int n);

/*
**	FT_PRINTF
*/

int					get_size(const char *fmt);
void				remove_conflict_flags(t_param *params);
int					get_flags(int fmt, t_flag *flags);
void				reset_params(t_param *params);
void				get_params(const char **fmt, t_param *params, va_list args);
intmax_t			convert_signed(t_param *params, intmax_t n);
intmax_t			convert_unsigned(t_param *params, uintmax_t n);
void				write_int(t_param *params, intmax_t n);
void				int_flags(t_param *params);
void				int_add_prefixes(char *str, int *i, t_param *params,
										int flag);
void				write_unsigned_int(t_param *params, uintmax_t n);
void				unsigned_flags(t_param *params);
int					unsigned_int_length(uintmax_t n);
void				write_octal(t_param *params, uintmax_t n);
int					oct_length(uintmax_t n);
char				*make_octal(uintmax_t n, t_param *params);
void				write_hex(t_param *params, uintmax_t n, int letters);
void				write_ptr(t_param *params, long int n);
void				hash_except(t_param *params, int letters);
int					hex_length(uintmax_t n);
void				write_char(t_param *params, unsigned char c);
void				write_string(t_param *params, char *str);
int					ft_printf(const char *fmt, ...);

#endif
