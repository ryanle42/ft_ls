/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:06:04 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:06:09 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	entlst_add_ents(t_entlst *entlst, t_ent *ents, char *path)
{
	t_entlst *curr;

	curr = entlst;
	if (!curr->ents)
	{
		curr->path = path;
		curr->ents = ents;
	}
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = (t_entlst *)malloc(sizeof(t_entlst));
		curr = curr->next;
		curr->path = path;
		curr->ents = ents;
		curr->next = NULL;
	}
}
