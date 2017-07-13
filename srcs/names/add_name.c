/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:03:14 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 19:16:35 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	add_name(t_names *head, char *name)
{
	t_names *curr;

	curr = head;
	if (!curr->name)
		curr->name = name;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = (t_names*)malloc(sizeof(t_names));
		curr = curr->next;
		curr->name = name;
		curr->next = NULL;
	}
}