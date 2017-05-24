/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:07:42 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/24 16:55:42 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

int	entlst_from_path(char *path, t_data *data)
{
	DIR *dirp;
	struct dirent *dp;
	t_ent *ents;
	char *name;

	if (NULL == (ents = ent_init()))
			return (-1);
	if (NULL != (dirp = opendir(path)))
	{
		if (data->cmds & CMD_R)
			recursion(path, data);
		else
		{
			while (NULL != (dp = readdir(dirp)))
			{
				if (dp->d_name[0] != '.')
				{
					name = ft_copystr(dp->d_name);
					read_ent(path, name, data, ents);
				}
			}
			entlst_add_ents(data->entlst, ents, path);
		}
		closedir(dirp);
	}
	else
	{
		read_ent(".", path, data, ents);
		entlst_add_ents(data->singent, ents, ".");
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
		if (argv[i][0] != '-')
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
	return (data);
}

/*
** 	ft_printf("R %i l %i r %i a %i t %i T %i\n", (data->cmds & CMD_R), (data->cmds & CMD_l), (data->cmds & CMD_r), \
**		(data->cmds & CMD_a), (data->cmds & CMD_t), (data->cmds & CMD_T));
*/

void	print_singent(t_data *data)
{
	while (data->singent)
	{
		if (data->singent->ents)
			print_ents(data->singent->ents, data);
		data->singent = data->singent->next;
	}
}

long		calc_total(t_ent *head)
{
	t_ent *curr;
	long total;

	total = 0;
	curr = head;
	while (curr && curr->name)
	{
		total += curr->sb.st_blocks;
		curr = curr->next;
	}
	return (total);
}

void	print_entlst(t_data *data, int argc)
{
	while (data->entlst)
	{
		if (data->entlst->ents)
		{
			if (ft_strcmp(data->entlst->path, ".") != 0 && (argc > 2 || data->cmds & CMD_R))
				ft_printf("%s:\n", data->entlst->path);
			if (data->cmds & CMD_l)
				ft_printf("total %li\n", calc_total(data->entlst->ents));
			print_ents(data->entlst->ents, data);
		}
		data->entlst = data->entlst->next;
	}	
}

int main(int argc, char **argv)
{
	t_data *data;

	if (NULL == (data = data_init()))
		return (-1);
	data->cmds = get_commands(argc, argv);
	parse_params(argc, argv, data);
	print_errlst(data->errors->nofile);
	print_singent(data);
	print_errlst(data->errors->pdeny);
	print_entlst(data, argc);
	return (0);
}



