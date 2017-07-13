/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:02:45 by rle               #+#    #+#             */
/*   Updated: 2017/04/05 15:17:33 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		oct_length(uintmax_t n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 8;
		i++;
	}
	return (i);
}

char	*make_octal(uintmax_t n, t_param *params)
{
	char		*base;
	char		*str;
	intmax_t	i;

	base = "01234567";
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * oct_length(n) + 1)))
		return (NULL);
	if (n == 0 && params->precision != 0)
	{
		str[i++] = '0';
		return (str);
	}
	while (n > 0)
	{
		str[i++] = *(base + (n % 8));
		n /= 8;
	}
	return (str);
}
