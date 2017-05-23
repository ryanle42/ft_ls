/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:46:39 by rle               #+#    #+#             */
/*   Updated: 2017/05/22 17:15:09 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*make_prefix(t_param *params, char *str)
{
	char	*prefix;
	int		i;

	i = 0;
	if (!(prefix = (char *)malloc(sizeof(char) * params->zeros + \
						params->flags->hash + 1)))
		return (NULL);
	if (params->zeros > 0)
	{
		while (i < params->zeros)
			prefix[i++] = '0';
	}
	else if (params->flags->hash && str[0] != '0')
		prefix[i++] = '0';
	prefix[i] = '\0';
	return (prefix);
}

static void	calc_sp_n_zeros(t_param *params, int length)
{
	if (params->flags->hash)
		params->width--;
	if (params->is_precision)
		params->zeros = params->precision - length;
	if (params->zeros < 0)
		params->zeros = 0;
	params->width -= (length + params->zeros);
	if (params->width < 0)
		params->width = 0;
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

void		write_octal(t_param *params, uintmax_t n)
{
	char	*str;
	int		length;

	n = convert_unsigned(params, n);
	str = make_octal(n, params);
	length = ft_strlen(str);
	str = ft_strrev(str, length);
	calc_sp_n_zeros(params, length);
	str = ft_strjoin(make_prefix(params, str), str, 3);
	if (!params->flags->minus)
		write_spaces(params);
	ft_putstr(str);
	if (params->flags->minus)
		write_spaces(params);
	params->counter += ft_strlen(str);
	free(str);
}
