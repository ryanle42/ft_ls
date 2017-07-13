/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:42:10 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:23:34 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	int_flags(t_param *params)
{
	if (params->flags->zero && params->flags->minus)
		params->flags->zero = 0;
	if (params->flags->zero && params->is_precision)
		params->flags->zero = 0;
	if (params->flags->plus && params->flags->space)
		params->flags->space = 0;
}

void	int_add_prefixes(char *str, int *i, t_param *params, int flag)
{
	while (params->zeros > 0)
	{
		str[(*i)++] = '0';
		params->zeros--;
	}
	if (flag && !params->flags->zero)
		str[(*i)++] = '-';
	else if (params->flags->plus && !params->flags->zero)
		str[(*i)++] = '+';
	else if (params->flags->space && !params->width)
		str[(*i)++] = ' ';
	str[(*i)] = '\0';
}
