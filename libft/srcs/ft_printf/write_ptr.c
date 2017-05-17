/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:45:56 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:58:54 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*convert_hex(uintmax_t n)
{
	char	*base;
	char	*str;
	int		length;
	int		i;

	i = 0;
	length = hex_length(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (n == 0)
		return ("0");
	base = "0123456789abcdef";
	while (n > 0)
	{
		str[i++] = *(base + (n % 16));
		n /= 16;
	}
	str[i] = '\0';
	str = ft_strrev(str, i);
	return (str);
}

static void	write_spaces(t_param *params)
{
	while (params->width > 0)
	{
		if (params->flags->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		params->width--;
		params->counter++;
	}
}

static void	calc_sp_n_zeros(t_param *params, int length)
{
	if (params->is_precision)
		params->zeros = params->precision - length;
	if (params->zeros < 0)
		params->zeros = 0;
	params->width -= (length + params->zeros);
	if (params->flags->plus)
		params->width -= 1;
	if (params->width < 0)
		params->width = 0;
}

void		write_ptr(t_param *params, long int n)
{
	char *str;

	str = convert_hex(n);
	if (n == 0)
		str = "0x0";
	if (n != 0)
		str = ft_strjoin("0x", str);
	calc_sp_n_zeros(params, ft_strlen(str));
	if (!params->flags->minus)
		write_spaces(params);
	ft_putstr(str);
	if (params->flags->minus)
		write_spaces(params);
	params->counter += ft_strlen(str);
	free(str);
}
