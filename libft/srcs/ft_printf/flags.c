/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:39:37 by rle               #+#    #+#             */
/*   Updated: 2017/05/07 22:49:44 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			get_flags(int fmt, t_flag *flags)
{
	if (fmt == '#')
		flags->hash++;
	if (fmt == '0')
		flags->zero++;
	if (fmt == ' ')
		flags->space++;
	if (fmt == '-')
		flags->minus++;
	if (fmt == '+')
		flags->plus++;
	if (fmt == '#' || fmt == '0' || fmt == ' ' || fmt == '-' || fmt == '+')
		return (1);
	return (0);
}

void		int_conflict_flags(t_param *params)
{
	if (params->flags->zero && params->flags->minus)
		params->flags->zero = 0;
	if (params->flags->plus && params->flags->space)
		params->flags->space = 0;
	if (params->flags->zero && (params->is_precision > 0))
		params->flags->zero = 0;
}

int			is_conversion(char fmt)
{
	if (fmt == 's' || fmt == 'S' || \
		fmt == 'p' || fmt == 'd' || \
		fmt == 'D' || fmt == 'i' || \
		fmt == 'o' || fmt == 'O' || \
		fmt == 'u' || fmt == 'U' || \
		fmt == 'x' || fmt == 'X' || \
		fmt == 'c' || fmt == 'C')
		return (1);
	return (0);
}

static int	get_size_help(char *size)
{
	if (ft_strcmp(size, "h") == 0)
		return (1);
	if (ft_strcmp(size, "j") == 0)
		return (2);
	if (ft_strcmp(size, "l") == 0)
		return (3);
	if (ft_strcmp(size, "z") == 0)
		return (4);
	if (ft_strcmp(size, "hh") == 0)
		return (5);
	if (ft_strcmp(size, "ll") == 0)
		return (6);
	return (0);
}

int			get_size(const char *fmt)
{
	int		i;
	char	*size;
	int		ret;

	i = 0;
	size = (char *)malloc(sizeof(char) * 3);
	while (!(is_conversion(*fmt)))
	{
		size[i] = *fmt++;
		i++;
	}
	size[i] = '\0';
	ret = get_size_help(size);
	free(size);
	return (ret);
}
