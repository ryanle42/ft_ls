/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 13:57:54 by rle               #+#    #+#             */
/*   Updated: 2017/04/05 14:04:27 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int n)
{
	int		length;
	char	*out;
	int		i;

	i = 0;
	length = (ft_strlen(str) + n);
	out = (char *)malloc(sizeof(char) * length + 1);
	while (str[i])
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	free(str);
	return (out);
}
