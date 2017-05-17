/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:13:10 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 17:41:40 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*out;

	out = (char *)big;
	i = 0;
	if (!(little[0]))
		return (out);
	while (out[i] && (i < len))
	{
		j = 0;
		k = i;
		while (out[k] == little[j] && out[k] && (k < len))
		{
			k++;
			j++;
		}
		if (!little[j])
			return (&out[k - j]);
		i++;
	}
	return (NULL);
}
