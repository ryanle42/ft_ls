/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:59:04 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 17:04:32 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *s;
	char *d;

	s = (char *)src;
	d = (char *)dst;
	if (s == d)
		return (d);
	if (s < d)
	{
		s = s + len - 1;
		d = d + len - 1;
		while (len-- > 0)
			*d-- = *s--;
	}
	else
		while (len-- > 0)
			*d++ = *s++;
	return (dst);
}
