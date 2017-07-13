/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errlst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:10:48 by rle               #+#    #+#             */
/*   Updated: 2017/05/27 18:45:50 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_errlst	*errlst_init(void)
{
	t_errlst *errlst;

	if (NULL == (errlst = (t_errlst *)malloc(sizeof(t_errlst))))
		return (NULL);
	errlst->name = NULL;
	errlst->msg = NULL;
	errlst->next = NULL;
	errlst->path = NULL;
	return (errlst);
}