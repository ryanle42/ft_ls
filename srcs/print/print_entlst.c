/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:23:59 by rle               #+#    #+#             */
/*   Updated: 2017/05/27 19:17:14 by rle              ###   ########.fr       */
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
			if (i != 0 || data->errors->pdeny->msg)
				ft_printf("\n");
			if (((ft_strcmp(data->entlst->path, ".") != 0) && (data->num_ents > 1 || \
				data->cmds & CMD_R)))
				ft_printf("%s:\n", data->entlst->path);
			if (data->cmds & CMD_l)
				ft_printf("total %li\n", calc_total(data->entlst->ents));
			print_ents(data->entlst->ents, data);
			i++;
		}
		data->entlst = data->entlst->next;
	}	
}