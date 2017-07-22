/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:46:23 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 16:14:03 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freestr(char *s1, char *s2, int opt)
{
	if (opt == 1 || opt == 3)
		free(s1);
	if (opt == 2 || opt == 3)
		free(s2);
}

char		*ft_strjoin(char *s1, char *s2, int opt)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!(str = (char *)malloc(sizeof(char) * (i + j) + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	freestr(s1, s2, opt);
	return (str);
}
