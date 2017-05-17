/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strn_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 16:36:08 by rle               #+#    #+#             */
/*   Updated: 2017/04/05 13:58:25 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strn_append(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*out;

	out = ft_realloc(s1, n);
	j = 0;
	while (out[j])
		j++;
	i = 0;
	while (i < n)
	{
		out[j] = s2[i];
		i++;
		j++;
	}
	out[j] = '\0';
	return (out);
}
