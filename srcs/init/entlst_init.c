/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entlst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:11:38 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 15:12:05 by rle              ###   ########.fr       */
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