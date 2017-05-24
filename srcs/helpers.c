/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 20:20:57 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/24 15:22:12 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

char	*name_from_path(char *path)
{
	int i;
	int j;
	char *name;

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

char *get_fpath(char *path, char *name)
{
	char *fpath;

	fpath = ft_strjoin(path, "/", 0);
	fpath = ft_strjoin(fpath, name, 0);
	return (fpath);
}

void	read_ent(char *path, char *name, t_data *data, t_ent *ents)
{
	struct stat	sb;
	char		*fpath;

	fpath = get_fpath(path, name);
	stat(fpath, &sb);
	if (errno == ENOENT)
		add_nofile(data->errors->nofile, name);
	else if (errno == EACCES)
		add_pdeny(data->errors->pdeny, path);
	else if (-1 == add_ent(fpath, name, ents))
		exit(1);
	errno = 0;
}
