/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:25:41 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:17:01 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

long	calc_total(t_ent *head)
{
	t_ent	*curr;
	long	total;

	total = 0;
	curr = head;
	while (curr && curr->name)
	{
		total += curr->sb.st_blocks;
		curr = curr->next;
	}
	return (total);
}

void	calc_spaces(t_ent *head, t_sp *spaces)
{
	spaces->fl_sz = 0;
	spaces->links = 0;
	spaces->name = 0;
	spaces->files = 0;
	while (head && head->name)
	{
		if (spaces->fl_sz < ft_int_length(head->sb.st_size))
			spaces->fl_sz = ft_int_length(head->sb.st_size) + 1;
		if (spaces->links < ft_int_length(head->sb.st_nlink))
			spaces->links = ft_int_length(head->sb.st_nlink);
		if (spaces->name < (int)ft_strlen(head->name))
			spaces->name = (int)ft_strlen(head->name);
		spaces->files++;
		head = head->next;
	}
}
