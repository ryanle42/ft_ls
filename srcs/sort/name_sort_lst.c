/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_sort_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:10:36 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 19:13:05 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	name_sort_lst(t_names *names)
{
	t_names *prev;

	while (names->next)
	{
		prev = names;
		names = names->next;
		if (!(is_sorted(prev->name, names->name)))
			ft_strswap(prev->name, names->name);
	}
}