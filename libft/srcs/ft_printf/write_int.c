/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:44:40 by rle               #+#    #+#             */
/*   Updated: 2017/05/21 18:46:52 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	int_length(intmax_t n)
{
	int i;

	i = 1;
	if (n < 0)
		n = -n;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	write_spaces(t_param *params, intmax_t n)
{
	if (params->flags->plus && n >= 0 && !params->flags->minus \
		&& params->flags->zero)
	{
		write(1, "+", 1);
		params->counter++;
	}
	if (n < 0 && !params->flags->minus && params->flags->zero)
	{
		write(1, "-", 1);
		params->counter++;
	}
	while (params->width > 0)
	{
		if (params->flags->zero && !params->is_precision)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		params->width--;
		params->counter++;
	}
}

static char	*int_to_str(intmax_t n, char *str, t_param *params)
{
	int flag;
	int i;

	i = 0;
	flag = 0;
	if (n < 0)
	{
		flag++;
		n *= -1;
	}
	if (!(str = (char *)malloc(sizeof(char) * (ft_int_length(n) + flag + \
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
	int_add_prefixes(str, &i, params, flag);
	return (ft_strrev(str, i));
}

static void	calc_sp_n_zeros(t_param *params, intmax_t n, int length)
{
	if (params->is_precision)
		params->zeros = params->precision - length + 1;
	if (params->zeros < 0)
		params->zeros = 0;
	params->width -= (length + params->zeros - 1);
	if ((params->flags->plus && n >= 0) || n < 0)
		params->width -= 1;
	if (params->width < 0)
		params->width = 0;
}

void		write_int(t_param *params, intmax_t n)
{
	char	*str;
	int		length;

	str = NULL;
	n = convert_signed(params, n);
	int_flags(params);
	length = int_length(n);
	calc_sp_n_zeros(params, n, length);
	str = int_to_str(n, str, params);
	if (!params->flags->minus)
		write_spaces(params, n);
	ft_putstr(str);
	if (params->flags->minus)
		write_spaces(params, n);
	params->counter += ft_strlen(str);
	free(str);
}
