/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:07:52 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 17:06:02 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

char	*name_from_path(char *path)
{
	int		i;
	int		j;
	char	*name;

	j = 0;
	i = 0;
	while (path[i])
		i++;
	while (path[i] != '/' && i >= 0)
	{
		j++;
		i--;
	}
	name = (char *)malloc(sizeof(char) * j + 1);
	j = 0;
	while (path[++i])
		name[j++] = path[i];
	name[j] = '\0';
	return (name);
}

void	rev_names(t_names **head)
{
	t_names *next;
	t_names *prev;
	t_names *curr;

	if ((*head)->next)
	{
		prev = *head;
		curr = (*head)->next;
		if (curr->next)
			next = curr->next;
		else
			next = NULL;
		prev->next = NULL;
		curr->next = prev;
		while (next)
		{
			prev = curr;
			curr = next;
			next = curr->next;
			curr->next = prev;
		}
		*head = curr;
	}
}

char	*get_fpath(char *path, char *name)
{
	char *fpath;

	fpath = ft_strjoin(path, "/", 0);
	fpath = ft_strjoin(fpath, name, 1);
	return (fpath);
}
