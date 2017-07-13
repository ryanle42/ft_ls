/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:04:33 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 17:58:02 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		k;
	char	*out;

	out = (char *)big;
	i = 0;
	if (!(out[i]) && !(little[i]))
		return (&out[i]);
	while (out[i])
	{
		j = 0;
		k = i;
		while (out[k] == little[j] && out[k])
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
