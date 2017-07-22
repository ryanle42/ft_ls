/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_add_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:17:20 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:42:56 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_names		*make_name_node(char *name)
{
	t_names *node;

	node = names_init();
	node->name = name;
	return (node);
}

void		insert_name_node(t_names *names, char *name)
{
	t_names *tmp;
	t_names *insert;

	insert = make_name_node(name);
	tmp = names->next;
	names->next = insert;
	insert->next = tmp;
}

void		swap_insert_node(t_names *names, char *name)
{
	char *tmp;

	tmp = names->name;
	names->name = name;
	insert_name_node(names, tmp);
}

static int	sort_add_help(t_data *data, t_names **curr, char *path, char *name)
{
	int cmp;

	(*curr) = (*curr)->next;
	if (data->cmds & CMD_t)
	{
		if ((cmp = ft_timecmp(get_fpath(path, (*curr)->name), \
			get_fpath(path, name))) == 0)
			cmp = ft_strcmp((*curr)->name, name);
	}
	else
		cmp = ft_strcmp((*curr)->name, name);
	return (cmp);
}

void		sort_add_name(t_data *data, char *path, t_names *head, char *name)
{
	t_names	*curr;
	int		cmp;

	curr = head;
	if (!curr->name)
		curr->name = name;
	else
	{
		if (data->cmds & CMD_t)
		{
			if ((cmp = ft_timecmp(get_fpath(path, curr->name), \
				get_fpath(path, name))) == 0)
				cmp = ft_strcmp(curr->name, name);
		}
		else
			cmp = ft_strcmp(curr->name, name);
		while ((cmp < 0) && curr->next)
		{
			cmp = sort_add_help(data, &curr, path, name);
		}
		if (cmp > 0)
			swap_insert_node(curr, name);
		else
			insert_name_node(curr, name);
	}
}
