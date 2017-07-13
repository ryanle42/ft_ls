/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:25:48 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 19:07:27 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	j = 0;
	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * ft_count_wds(s, c) + 1)))
		return (NULL);
	while (s[i] && (j < ft_count_wds(s, c)))
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(str[j] = (char *)malloc(sizeof(char) * ft_wd_len(s, c, i) + 1)))
			return (NULL);
		while (s[i] != c && s[i])
			str[j][k++] = s[i++];
		str[j][k] = '\0';
		j++;
	}
	str[j] = NULL;
	return (str);
}
