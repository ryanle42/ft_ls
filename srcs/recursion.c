/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:39:36 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/27 18:18:23 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	recursion(char *path, t_data *data)
{
	t_names *names;
	DIR *dirp;
	struct dirent *dp;
	t_ent *ents;

	names = names_init();
	if (NULL == (ents = ent_init()))
		return ;
	if (NULL != (dirp = opendir(path)))
	{
		while (NULL != (dp = readdir(dirp)))
			sort_add_name(names, ft_copystr(dp->d_name));
		while (names && names->name)
		{
			if ((data->cmds & CMD_a) || names->name[0] != '.')
				read_ent(path, names->name, data, ents);
			names = names->next;
		}
		closedir(dirp);
		entlst_add_ents(data->entlst, ents, path);
	}
	else
		return ;
	names = names_init();
	if (NULL != (dirp = opendir(path)))
	{
		while (NULL != (dp = readdir(dirp)))
			sort_add_name(names, ft_copystr(dp->d_name));
		while (names && names->name)
		{
			if ((ft_strcmp(names->name, ".") != 0) && \
				(ft_strcmp(names->name, "..") != 0) && \
				((data->cmds & CMD_a) || names->name[0] != '.'))
					recursion(get_fpath(path, names->name), data);
				names = names->next;
		}
		closedir(dirp);
	}
}