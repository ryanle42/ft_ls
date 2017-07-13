/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:26:38 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/26 18:41:07 by rle              ###   ########.fr       */
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