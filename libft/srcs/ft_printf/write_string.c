/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 14:48:25 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:25:33 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	write_spaces(t_param *params)
{
	while (params->width > 0)
	{
		write(1, " ", 1);
		params->width--;
		params->counter++;
	}
}

static void	calc_sp(t_param *params, int length)
{
	if (params->is_precision)
	{
		if (params->precision > length)
			params->width -= length;
		else
			params->width -= params->precision;
	}
	else
		params->width -= length;
}

void		write_string(t_param *params, char *str)
{
	int i;
	int length;

	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	i = 0;
	calc_sp(params, length);
	if (!params->flags->minus)
		write_spaces(params);
	if (params->is_precision)
		while (str[i] && i < params->precision)
		{
			write(1, &str[i], 1);
			params->counter++;
			i++;
		}
	else
	{
		ft_putstr(str);
		params->counter += ft_strlen(str);
	}
	if (params->flags->minus)
		write_spaces(params);
}
