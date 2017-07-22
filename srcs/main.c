/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:03:33 by rle               #+#    #+#             */
/*   Updated: 2017/07/21 17:29:22 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static t_ent	*entlst_from_path_help(t_data *data, char *path, \
	DIR **dirp, t_names **head)
{
	struct dirent	*dp;
	t_ent			*ents;
	t_names			*curr;

	curr = *head;
	if (NULL == (ents = ent_init()))
		return (NULL);
	if (data->cmds & CMD_R)
		recursion(path, data);
	else
	{
		while (NULL != (dp = readdir((*dirp))))
			sort_add_name(data, path, curr, ft_copystr(dp->d_name));
		while (curr && curr->name)
		{
			if ((data->cmds & CMD_a) || curr->name[0] != '.')
				read_ent(path, curr->name, data, ents);
			curr = curr->next;
		}
		entlst_add_ents(data->entlst, ents, path);
	}
	closedir((*dirp));
	free_names(head);
	return (ents);
}

int				entlst_from_path(char *path, t_data *data)
{
	DIR				*dirp;
	t_ent			*ents;
	t_names			*names;

	ents = NULL;
	if (NULL != (dirp = opendir(path)))
	{
		names = names_init();
		if (NULL == (ents = entlst_from_path_help(data, path, &dirp, &names)))
			return (-1);
	}
	else
	{
		if (errno == EACCES)
		{
			add_pdeny(path, ents);
			entlst_add_ents(data->entlst, ents, path);
		}
		else
			read_ent(".", path, data, data->singent);
		errno = 0;
	}
	return (1);
}

int				parse_params(int start, int argc, char **argv, t_data *data)
{
	data->nl = argc - start;
	if (start == argc)
		entlst_from_path(".", data);
	while (start < argc)
	{
		data->num_ents++;
		entlst_from_path(argv[start], data);
		start++;
	}
	return (1);
}

t_data			*data_init(void)
{
	t_data *data;

	if (NULL == (data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (NULL == (data->errors = errors_init()))
		return (NULL);
	if (NULL == (data->entlst = entlst_init()))
		return (NULL);
	if (NULL == (data->singent = ent_init()))
		return (NULL);
	data->num_ents = 0;
	data->nl = 0;
	return (data);
}

int				main(int argc, char **argv)
{
	t_data	*data;
	int		start;

	if (NULL == (data = data_init()))
		return (-1);
	data->cmds = get_commands(argc, argv);
	start = sort_names(data, argc, argv);
	parse_params(start, argc, argv, data);
	print_singent(data);
	print_errlst(data->errors->nofile, data->num_ents);
	print_entlst(data);
	return (0);
}
