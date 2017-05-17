/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:44:40 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:59:02 by rle              ###   ########.fr       */
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

void		write_char(t_param *params, unsigned char c)
{
	params->width--;
	if (!params->flags->minus)
		write_spaces(params);
	ft_putchar(c);
	if (params->flags->minus)
		write_spaces(params);
	params->counter += 1;
}
