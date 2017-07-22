/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_singent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:23:34 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:16:33 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	print_singent(t_data *data)
{
	if (data->singent->name)
	{
		if (data->cmds & CMD_r)
			print_r_ents(data->singent, data);
		else
			print_ents(data->singent, data);
		if (data->entlst->ents)
			ft_printf("\n");
	}
}
