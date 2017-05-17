/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:38:54 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 19:15:34 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*itoa_two(long m, char *str, int flag, int i)
{
	if (m == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (m != 0)
	{
		str[i++] = (m % 10) + '0';
		m /= 10;
	}
	if (flag)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str, i));
}

char			*ft_itoa(int n)
{
	char	*str;
	int		flag;
	int		i;
	long	m;

	i = 0;
	flag = 0;
	m = n;
	if (m < 0)
	{
		flag = 1;
		m *= -1;
	}
	if (!(str = (char *)malloc(sizeof(char) * ft_int_length(m) + 1)))
		return (NULL);
	return (itoa_two(m, str, flag, i));
}
