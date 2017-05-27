/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:09:49 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 15:09:56 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_error	*errors_init(void)
{
	t_error *error;

	if (NULL == (error = (t_error *)malloc(sizeof(t_error))))
		return (NULL);
	error->nofile = errlst_init();
	error->pdeny = errlst_init();
	return (error);
}