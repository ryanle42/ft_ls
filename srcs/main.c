/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:07:42 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/27 19:16:22 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

int	entlst_from_path(char *path, t_data *data)
{
	DIR *dirp;
	struct dirent *dp;
	t_ent *ents;
	t_names *names;

	names = names_init();
	if (NULL == (ents = ent_init()))
			return (-1);
	if (NULL != (dirp = opendir(path)))
	{
		if (data->cmds & CMD_R)
			recursion(path, data);
		else
		{
			while (NULL != (dp = readdir(dirp)))
				sort_add_name(names, ft_copystr(dp->d_name));
			while (names && names->name)
			{
				if ((data->cmds & CMD_a) || names->name[0] != '.')
					read_ent(path, names->name, data, ents);
				names = names->next;
			}
			entlst_add_ents(data->entlst, ents, path);
		}
		closedir(dirp);
	}
	else
	{
		if (errno == EACCES)
			add_pdeny(data->errors->pdeny, path);
		else
		{
			read_ent(".", path, data, ents);
			entlst_add_ents(data->singent, ents, ".");
		}
		errno = 0;
	}
	return (1);
}

int	parse_params(int argc, char **argv, t_data *data)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-')
			break;
	}
	if (i == argc)
		entlst_from_path(".", data);
	while (i < argc)
	{
		data->num_ents++;
		entlst_from_path(argv[i], data);
		i++;
	}
	return (1);
}

t_data	*data_init(void)
{
	t_data *data;

	if (NULL == (data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (NULL == (data->errors = errors_init()))
		return (NULL);
	if (NULL == (data->entlst = entlst_init()))
		return (NULL);
	if (NULL == (data->singent = entlst_init()))
		return (NULL);
	data->num_ents = 0;
	return (data);
}

/*
** 	ft_printf("R %i l %i r %i a %i t %i T %i\n", (data->cmds & CMD_R), (data->cmds & CMD_l), (data->cmds & CMD_r), \
**		(data->cmds & CMD_a), (data->cmds & CMD_t), (data->cmds & CMD_T));
*/

int main(int argc, char **argv)
{
	t_data *data;

	if (NULL == (data = data_init()))
		return (-1);
	data->cmds = get_commands(argc, argv);
	parse_params(argc, argv, data);
	sort_names(1, argc, argv);
	print_errlst(data->errors->nofile, 0);
	print_singent(data);
	print_errlst(data->errors->pdeny, data->num_ents);
	print_entlst(data);
	return (0);
}



