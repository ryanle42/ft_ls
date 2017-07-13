/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:49:00 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:58:37 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	add_prefixes(char *str, int *i, t_param *params)
{
	while (params->zeros > 0)
	{
		str[(*i)++] = '0';
		params->zeros--;
	}
	if (params->flags->plus && !params->flags->zero)
		str[(*i)++] = '+';
	else if (params->flags->space && !params->width)
		str[(*i)++] = ' ';
	str[(*i)] = '\0';
}

static void	write_spaces(t_param *params)
{
	if (params->flags->plus && !params->flags->minus && params->flags->zero)
	{
		write(1, "+", 1);
		params->counter++;
	}
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

static char	*int_to_str(uintmax_t n, char *str, t_param *params)
{
	int i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_int_length(n) + \
		params->flags->plus + params->zeros + 1))))
		return (NULL);
	if (n == 0 && params->precision != 0)
		str[i++] = '0';
	else
	{
		while (n != 0)
		{
			str[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	add_prefixes(str, &i, params);
	return (ft_strrev(str, i));
}

static void	calc_sp_n_zeros(t_param *params, int length)
{
	if (params->is_precision)
		params->zeros = params->precision - length + 1;
	if (params->zeros < 0)
		params->zeros = 0;
	params->width -= (length + params->zeros - 1);
	if (params->flags->plus)
		params->width -= 1;
	if (params->width < 0)
		params->width = 0;
}

void		write_unsigned_int(t_param *params, uintmax_t n)
{
	char	*str;
	int		length;

	str = NULL;
	n = convert_unsigned(params, n);
	unsigned_flags(params);
	length = unsigned_int_length(n);
	calc_sp_n_zeros(params, length);
	str = int_to_str(n, str, params);
	if (!params->flags->minus)
		write_spaces(params);
	ft_putstr(str);
	if (params->flags->minus)
		write_spaces(params);
	params->counter += ft_strlen(str);
	free(str);
}
