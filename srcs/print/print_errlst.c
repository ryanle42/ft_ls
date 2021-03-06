/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:14:14 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 17:45:28 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	print_errlst(t_errlst *error, int i)
{
	t_errlst *curr;

	curr = error;
	i = 0;
	if (error && error->msg)
	{
		while (error && error->msg)
		{
			ft_printf("%s", error->msg);
			curr = error->next;
			if (curr)
				ft_printf("\n");
			free(error->msg);
			free(error);
			error = curr;
		}
		ft_printf("\n");
	}
}
