/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:14:32 by rle               #+#    #+#             */
/*   Updated: 2016/12/02 11:55:50 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*out;

	out = (unsigned char *)s;
	while (n > 0)
	{
		if (*out != (unsigned char)c)
			out++;
		else
			return (out);
		n--;
	}
	return (NULL);
}
