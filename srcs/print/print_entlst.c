/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:23:59 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:08:34 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	print_entlst(t_data *data)
{
	int i;

	i = 0;
	while (data->entlst)
	{
		if (data->entlst->ents)
		{
			if (i != 0)
				ft_printf("\n");
			if (data->num_ents > 1)
				ft_printf("%s:\n", data->entlst->path);
			else if (i > 0)
				ft_printf("%s:\n", data->entlst->path);
			if (data->cmds & CMD_l && !(data->entlst->ents->err))
				ft_printf("total %li\n", calc_total(data->entlst->ents));
			if (data->cmds & CMD_r)
				print_r_ents(data->entlst->ents, data);
			else
				print_ents(data->entlst->ents, data);
			i++;
		}
		data->entlst = data->entlst->next;
	}
}
