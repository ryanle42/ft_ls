/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:53:23 by rle               #+#    #+#             */
/*   Updated: 2016/12/05 17:50:43 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_new(int n, int fd)
{
	write(fd, &n, 1);
}

static int		ft_putnum(long n, int fd)
{
	if (n < 0)
	{
		ft_new('-', fd);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnum(n / 10, fd);
		ft_putnum(n % 10, fd);
	}
	else
		ft_new(n + '0', fd);
	return (0);
}

void			ft_putnbr_fd(int n, int fd)
{
	ft_putnum(n, fd);
}
