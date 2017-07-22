/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdeny.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:16:19 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:48:58 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static char	*pdeny_msg(char *name)
{
	char *msg;

	msg = ft_strjoin("", "./ft_ls: ", 0);
	msg = ft_strjoin(msg, name, 0);
	msg = ft_strjoin(msg, ": Permission denied", 0);
	return (msg);
}

void		print_pdeny(char *path, t_data *data)
{
	char *name;

	name = name_from_path(path);
	if (data->nl > 1)
		ft_printf("%s:\n", path);
	ft_printf("%s\n", pdeny_msg(name));
	if (data->num_ents > 1)
		ft_printf("\n");
}

int			add_pdeny(char *path, t_ent *head)
{
	t_ent		*curr;
	t_ent		*prev;
	char		*name;

	curr = head;
	name = name_from_path(path);
	if (!curr->name)
	{
		curr->err = pdeny_msg(name);
		curr->name = name;
		return (1);
	}
	while (curr->next)
		curr = curr->next;
	if (NULL == (curr->next = (t_ent *)malloc(sizeof(t_ent))))
		return (-1);
	prev = curr;
	curr = curr->next;
	curr->name = name;
	curr->err = pdeny_msg(name);
	stat(path, &(curr->sb));
	curr->next = NULL;
	curr->prev = prev;
	return (1);
}
