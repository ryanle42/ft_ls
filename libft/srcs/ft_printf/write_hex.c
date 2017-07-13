/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:38:55 by rle               #+#    #+#             */
/*   Updated: 2017/05/22 17:14:43 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	write_spaces(t_param *params)
{
	while (params->width > 0)
	{
		if (params->flags->zero && !params->flags->minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		params->width--;
		params->counter++;
	}
	while (params->zeros > 0)
	{
		write(1, "0", 1);
		params->zeros--;
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

static char	*convert_hex(t_param *params, uintmax_t n, int letters)
{
	char	*base;
	char	*str;
	int		length;
	int		i;

	i = 0;
	length = hex_length(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (n == 0 && params->precision == 0)
		return ("");
	if (n == 0)
		return ("0");
	if (letters == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	while (n > 0)
	{
		str[i++] = *(base + (n % 16));
		n /= 16;
	}
	str[i] = '\0';
	str = ft_strrev(str, i);
	return (str);
}

void		write_hex(t_param *params, uintmax_t n, int letters)
{
	char	*str;

	n = convert_unsigned(params, n);
	str = convert_hex(params, n, letters);
	if (params->flags->hash && n != 0 && !params->flags->zero)
	{
		if (letters == 0)
			str = ft_strjoin("0x", str, 0);
		else
			str = ft_strjoin("0X", str, 0);
	}
	if (params->flags->hash && n != 0 && params->flags->zero)
		hash_except(params, letters);
	calc_sp_n_zeros(params, ft_strlen(str));
	if (!params->flags->minus)
		write_spaces(params);
	ft_putstr(str);
	if (params->flags->minus)
		write_spaces(params);
	params->counter += ft_strlen(str);
	free(str);
}
