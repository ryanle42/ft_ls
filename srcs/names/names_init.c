/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:01:57 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 17:27:34 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_names	*names_init(void)
{
	t_names *names;

	names = (t_names*)malloc(sizeof(t_names));
	names->name = NULL;
	names->next = NULL;
	return (names);
}
