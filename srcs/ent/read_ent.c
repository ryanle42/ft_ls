/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:45:25 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 17:12:45 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	read_ent(char *path, char *name, t_data *data, t_ent *ents)
{
	struct stat	sb;
	char		*fpath;

	fpath = get_fpath(path, name);
	stat(fpath, &sb);
	if (errno == ENOENT)
		add_nofile(data->errors->nofile, name);
	else if (errno == EACCES)
		add_pdeny(path, ents);
	else if (-1 == add_ent(fpath, name, ents))
		exit(1);
	errno = 0;
	free(fpath);
}
