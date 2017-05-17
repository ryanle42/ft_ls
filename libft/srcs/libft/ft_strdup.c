/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:36:28 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 17:05:26 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*out;

	i = 0;
	while (s1[i])
		i++;
	if ((out = (char *)malloc(sizeof(char) * i + 1)))
	{
		i = 0;
		while (s1[i])
		{
			out[i] = s1[i];
			i++;
		}
		out[i] = '\0';
	}
	else
		return (0);
	return (out);
}
