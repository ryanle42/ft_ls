/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:33:30 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:23:20 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		hex_length(uintmax_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	hash_except(t_param *params, int letters)
{
	if (letters == 0)
		ft_putstr("0x");
	else
		ft_putstr("0X");
	params->width -= 2;
	params->counter += 2;
}
