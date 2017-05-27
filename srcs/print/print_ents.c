/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ents.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:58:21 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 16:06:50 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void		print_ents(t_ent *head, t_data *data)
{
	t_sp spaces;

	int i;
	i = 0;
	if (head && head->name)
		calc_spaces(head, &spaces);
	else 
		return ;
	while (head && head->name)
	{
		if (data->cmds & CMD_l)
			print_l(head, spaces);
		else
		{
			if (i % 6 == 0 || !head->prev)
				ft_printf("%s", head->name);
			else
				ft_printf("%*s", 2 + spaces.name - (int)ft_strlen(head->prev->name) + (int)ft_strlen(head->name), head->name); // -t -l
			if (i > 0 && ((i + 1) % 6 == 0) && head->next)
				ft_printf("\n");
		}
		i++;
		head = head->next;
	}
	if (!(data->cmds & CMD_l))
		ft_printf("\n");
}
