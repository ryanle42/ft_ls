/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:39:36 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/21 23:39:43 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	recursion(char *path, t_data *data)
{
	char *name;
	DIR *dirp;
	struct dirent *dp;
	t_ent *ents;

	if (NULL == (files = files_init()))
		return ;
	if (NULL != (dirp = opendir(path)))
	{
		if (ft_strcmp(path, ".") != 0)
			ft_printf("\n%s:\n", path);
		path = ft_strjoin(path, "/", 0);
		while (NULL != (dp = readdir(dirp)))
		{
			if (dp->d_name[0] != '.')
			{
				name = ft_copystr(dp->d_name);
				read_file(path, name, data, files);
			}
		}
		closedir(dirp);
		print_files(files);
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
				name = ft_strjoin(path, dp->d_name, 0);
				recursion(name, data);
			}
		}
		closedir(dirp);
	}
}