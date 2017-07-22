/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:46:48 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 17:12:49 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static int	add_ent_help(t_ent **curr, char *path, char *name)
{
	stat(path, &((*curr)->sb));
	if (NULL == ((*curr)->pw = getpwuid((*curr)->sb.st_uid)))
		return (-1);
	if (NULL == ((*curr)->grp = getgrgid((*curr)->sb.st_gid)))
		return (-1);
	(*curr)->name = name;
	(*curr)->err = NULL;
	return (1);
}

int			add_ent(char *path, char *name, t_ent *head)
{
	t_ent *curr;
	t_ent *prev;

	curr = head;
	if (!curr->name)
		return (add_ent_help(&curr, path, name));
	while (curr->next)
		curr = curr->next;
	if (NULL == (curr->next = (t_ent *)malloc(sizeof(t_ent))))
		return (-1);
	prev = curr;
	curr = curr->next;
	curr->name = name;
	stat(path, &(curr->sb));
	if (NULL == (curr->pw = getpwuid(curr->sb.st_uid)))
		return (-1);
	if (NULL == (curr->grp = getgrgid(curr->sb.st_gid)))
		return (-1);
	curr->next = NULL;
	curr->err = NULL;
	curr->prev = prev;
	return (1);
}
