/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:40:40 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:45:12 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	get_params(const char **fmt, t_param *params)
{
	while (get_flags(**fmt, params->flags) != 0)
		(*fmt)++;
	while (ft_isdigit(**fmt))
	{
		params->width *= 10;
		params->width += (**fmt - '0');
		(*fmt)++;
	}
	if (**fmt == '.')
	{
		(*fmt)++;
		params->is_precision = 1;
		params->precision = 0;
		while (ft_isdigit(**fmt))
		{
			params->precision *= 10;
			params->precision += (**fmt - '0');
			(*fmt)++;
		}
	}
	params->size = get_size(*fmt);
	if (params->size > 4)
		(*fmt) += 2;
	else if (params->size > 0)
		(*fmt)++;
}

void	reset_params(t_param *params)
{
	params->flags->hash = 0;
	params->flags->minus = 0;
	params->flags->plus = 0;
	params->flags->space = 0;
	params->flags->zero = 0;
	params->precision = 1;
	params->is_precision = 0;
	params->width = 0;
	params->counter = 0;
	params->zeros = 0;
}
