/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_converters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:37:50 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:24:59 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

intmax_t	convert_signed(t_param *params, intmax_t n)
{
	if (params->size == 1)
		n = (short)n;
	else if (params->size == 2)
		n = (intmax_t)n;
	else if (params->size == 3)
		n = (long)n;
	else if (params->size == 4)
		n = (size_t)n;
	else if (params->size == 5)
		n = (char)n;
	else if (params->size == 6)
		n = (long long)n;
	else
		n = (int)n;
	return (n);
}

intmax_t	convert_unsigned(t_param *params, uintmax_t n)
{
	if (params->size == 1)
		n = (unsigned short)n;
	else if (params->size == 2)
		n = (uintmax_t)n;
	else if (params->size == 3)
		n = (unsigned long)n;
	else if (params->size == 4)
		n = (size_t)n;
	else if (params->size == 5)
		n = (unsigned char)n;
	else if (params->size == 6)
		n = (unsigned long long)n;
	else
		n = (unsigned int)n;
	return (n);
}
