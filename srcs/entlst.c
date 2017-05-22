/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:26:38 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/22 00:27:17 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_entlst	*entlst_init(void)
{
	t_entlst *entlst;

	if (NULL == (entlst = (t_entlst*)malloc(sizeof(t_entlst))))
		return (NULL);
	entlst->next = NULL;
	entlst->ents = NULL;
	return (entlst);
}

void		entlst_add_ents(t_entlst *entlst, t_ent *ents)
{
	t_entlst *curr;

	curr = entlst;
	if (!curr->ents)
		curr->ents = ents;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = (t_entlst *)malloc(sizeof(t_entlst));
		curr = curr->next;
		curr->ents = ents;
		curr->next = NULL;
	}
}