/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:44:59 by rle               #+#    #+#             */
/*   Updated: 2017/05/17 16:12:41 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	handlers(const char *fmt, t_param *params, va_list args)
{
	if (*fmt == 'd' || *fmt == 'i')
		write_int(params, va_arg(args, intmax_t));
	else if (*fmt == 'u' || *fmt == 'D' || *fmt == 'U')
		write_unsigned_int(params, va_arg(args, uintmax_t));
	else if (*fmt == 'o' || *fmt == 'O')
		write_octal(params, va_arg(args, uintmax_t));
	else if (*fmt == 'c' || *fmt == 'C')
		write_char(params, va_arg(args, int));
	else if (*fmt == 'x')
		write_hex(params, va_arg(args, uintmax_t), 0);
	else if (*fmt == 'X')
		write_hex(params, va_arg(args, uintmax_t), 1);
	else if (*fmt == 'p')
		write_ptr(params, (long int)va_arg(args, void*));
	else if (*fmt == 's' || *fmt == 'S')
		write_string(params, va_arg(args, char*));
	else if (*fmt == '%')
		write_char(params, 37);
}

static void	print_else(const char *fmt, int *counter)
{
	write(1, fmt, 1);
	(*counter)++;
}

int			ft_printf(const char *fmt, ...)
{
	int		counter;
	t_param	*params;
	va_list	args;

	va_start(args, fmt);
	counter = 0;
	params = (t_param*)malloc(sizeof(t_param));
	params->flags = (t_flag*)malloc(sizeof(t_flag));
	while (*fmt)
	{
		if (*fmt == '%')
		{
			reset_params(params);
			fmt++;
			get_params(&fmt, params, args);
			handlers(fmt, params, args);
			counter += params->counter;
		}
		else
			print_else(fmt, &counter);
		fmt++;
	}
	free(params->flags);
	free(params);
	return (counter);
}
