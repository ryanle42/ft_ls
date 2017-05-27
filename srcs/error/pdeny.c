/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pdeny.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:16:19 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 15:59:51 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static char	*pdeny_msg(char *name)
{
	char *msg;

	msg = ft_strjoin("", "./ft_ls: ", 0);
	msg = ft_strjoin(msg, name, 1);
	msg = ft_strjoin(msg, ": Permission denied", 1);
	return (msg);
}

void	add_pdeny(t_errlst *head, char *path)
{
	t_errlst	*curr;
	char		*name;

	name = name_from_path(path);
	curr = head;
	if (!curr->name)
	{
		curr->name = name;
		curr->msg = pdeny_msg(name);
	}
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = errlst_init();
		curr = curr->next;
		curr->name = name;
		curr->msg = pdeny_msg(name);
	}
}