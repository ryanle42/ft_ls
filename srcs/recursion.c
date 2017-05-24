/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:39:36 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/23 22:12:35 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	recursion(char *path, t_data *data)
{
	char *name;
	DIR *dirp;
	struct dirent *dp;
	t_ent *ents;

	if (NULL == (ents = ent_init()))
		return ;
	if (NULL != (dirp = opendir(path)))
	{
		while (NULL != (dp = readdir(dirp)))
		{
			if (dp->d_name[0] != '.')
			{
				name = ft_copystr(dp->d_name);
				read_ent(path, name, data, ents);
			}
		}
		closedir(dirp);
		entlst_add_ents(data->entlst, ents, path);
	}
	else
		return ;
	if (NULL != (dirp = opendir(path)))
	{
		while (NULL != (dp = readdir(dirp)))
		{
			if (dp->d_name[0] != '.' && \
				ft_strcmp(dp->d_name, ".") != 0 && \
				ft_strcmp(dp->d_name, "..") != 0)
			{
				recursion(get_fpath(path, dp->d_name), data);
			}
		}
		closedir(dirp);
	}
}