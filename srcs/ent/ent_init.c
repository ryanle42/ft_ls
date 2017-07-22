/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ent_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:46:19 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 15:46:29 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_ent		*ent_init(void)
{
	t_ent *ent;

	if (NULL == (ent = (t_ent *)malloc(sizeof(t_ent))))
		return (NULL);
	ent->name = NULL;
	ent->next = NULL;
	ent->prev = NULL;
	ent->err = NULL;
	return (ent);
}
