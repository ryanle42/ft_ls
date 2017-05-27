/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_singent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:23:34 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 15:24:44 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	print_singent(t_data *data)
{
	while (data->singent)
	{
		if (data->singent->ents)
			print_ents(data->singent->ents, data);
		data->singent = data->singent->next;
	}
}