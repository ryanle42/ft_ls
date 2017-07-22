/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:52:03 by rle               #+#    #+#             */
/*   Updated: 2017/07/21 17:31:57 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static void	recursion_help(DIR **dirp, t_data *data, \
	char *path)
{
	struct dirent	*dp;
	t_names			*curr;
	t_names			*head;

	head = names_init();
	curr = head;
	while (NULL != (dp = readdir(*dirp)))
		sort_add_name(data, path, curr, ft_copystr(dp->d_name));
	if (data->cmds & CMD_r)
		rev_names(&curr);
	while (curr && curr->name)
	{
		if ((ft_strcmp(curr->name, ".") != 0) && \
			(ft_strcmp(curr->name, "..") != 0) && \
			((data->cmds & CMD_a) || curr->name[0] != '.'))
			recursion(get_fpath(path, curr->name), data);
		curr = curr->next;
	}
	free_names(&head);
	closedir(*dirp);
}

static void	norm_cheat(t_names **head, t_ent **ents)
{
	*head = names_init();
	*ents = ent_init();
}

void		recursion(char *path, t_data *data)
{
	t_names			*head;
	t_names			*curr;
	DIR				*dirp;
	struct dirent	*dp;
	t_ent			*ents;

	norm_cheat(&head, &ents);
	curr = head;
	if (NULL != (dirp = opendir(path)))
	{
		while (NULL != (dp = readdir(dirp)))
			sort_add_name(data, path, curr, ft_copystr(dp->d_name));
		while (curr && curr->name)
		{
			if ((data->cmds & CMD_a) || curr->name[0] != '.')
				read_ent(path, curr->name, data, ents);
			curr = curr->next;
		}
		closedir(dirp);
		entlst_add_ents(data->entlst, ents, path);
	}
	else
		return ;
	if (NULL != (dirp = opendir(path)))
		recursion_help(&dirp, data, path);
}
