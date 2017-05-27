/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nofile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:15:07 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 15:59:55 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static char	*nofile_msg(char *name)
{
	char *msg;

	msg = ft_strjoin("./ft_ls: ", name, 0);
	msg = ft_strjoin(msg, ": No such file or directory", 1);
	return (msg);
}

void	add_nofile(t_errlst *head, char *name)
{
	t_errlst	*curr;

	curr = head;
	if (!curr->name)
	{
		curr->name = name;
		curr->msg = nofile_msg(name);
	}
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = errlst_init();
		curr = curr->next;
		curr->name = name;
		curr->msg = nofile_msg(name);
	}
}