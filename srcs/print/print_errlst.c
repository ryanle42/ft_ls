/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:14:14 by rle               #+#    #+#             */
/*   Updated: 2017/05/27 19:16:28 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	print_errlst(t_errlst *error, int i)
{
	if (error && error->msg)
	{
		while (error && error->msg)
		{
			if (i > 1)
				ft_printf("%s:\n", error->path);
			ft_printf("%s", error->msg);
			if (error->next)
				ft_printf("\n");
			error = error->next;
		}
		ft_printf("\n");
	}
}