/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:58:53 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 18:04:57 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0 && (!(s1[0]) || !(s2[0])))
		return (0);
	while (*s1 && *s2 && (*s1 == *s2) && (n > 0))
	{
		s1++;
		s2++;
		n--;
	}
	if (*(s1 - 1) == *(s2 - 1) && n == 0)
		return (0);
	if (*s1 == *s2)
		return (0);
	if (!(*s1) && *s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	if (*s1 && !(*s2))
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
