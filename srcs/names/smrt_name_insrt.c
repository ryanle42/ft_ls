/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smrt_name_insrt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:17:20 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 20:07:30 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	insert_name_node(t_names *names, t_names *insert)
{
	t_names *tmp;

	tmp = names->next;
	names->next = insert;
	insert->next = tmp;
}

t_names *make_name_node(char *name)
{
	t_names *node;

	node = names_init();
	node->name = name;
	return (node);
}

void	smrt_name_insrt(t_names *head, char *name)
{
	t_names *curr;
	t_names *tmp;

	curr = head;
	if (!curr->name)
		curr->name = name;
	else
	{
		if (!curr->next)
		{
			if (!(is_sorted(curr->name, name)))
			{
				curr->next = make_name_node(curr->name);
				curr->name = name;
			}
			else
				curr->next = make_name_node(name);
		}
		else
		{
			while (curr->next)
			{
				ft_printf("curr->name: %s\nname: %s\n\n", curr->name, name);
				if (!is_sorted(curr->name, name))
				{
					ft_printf("not sorted!^\n\n");
					tmp = make_name_node(curr->name);
					curr->name = name;
					insert_name_node(curr, tmp);
					return ;
				}
				curr = curr->next;
			}
			curr->next = make_name_node(name);
		}
	}
}