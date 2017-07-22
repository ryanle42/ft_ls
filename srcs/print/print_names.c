/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_names.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 17:46:41 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:16:24 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	print_names(t_names *names)
{
	t_names *curr;

	curr = names;
	while (curr && curr->name)
	{
		ft_printf("%s ", curr->name);
		curr = curr->next;
	}
	ft_printf("\n");
}
