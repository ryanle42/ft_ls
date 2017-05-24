/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:07:42 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/23 22:16:48 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

int	get_stat(int argc, char **argv, t_data *data)
{
	int i;
	DIR *dirp;
	struct dirent *dp;
	char *path;
	char *name;
	t_ent *ents;

	i = 0;
	if (argc == 1)
	{
		if (data->cmds & CMD_R)
			recursion(".", data);
		else
		{
			if (NULL == (ents = ent_init()))
				return (-1);
			if (NULL == (dirp = opendir(".")))
			{
				ft_printf("Cannot open .");
				exit(1);
			}
			while (NULL != (dp = readdir(dirp)))
			{
				if (dp->d_name[0] != '.')
				{
					name = ft_copystr(dp->d_name);
					read_ent(".", name, data, ents);
				}
			}
			entlst_add_ents(data->entlst, ents, ".");
			closedir(dirp);
		}
	}
	while (++i < argc)
	{
		if (argv[i][0] != '-')
		{

			if (NULL == (ents = ent_init()))
				return (-1);
			path = argv[i];
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
					entlst_add_ents(data->entlst, ents, argv[i]);
				}
				closedir(dirp);
			}
			else
			{
				read_ent(".", path, data, ents);
				entlst_add_ents(data->singent, ents, ".");
			}
		}
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
			print_ents(data->singent->ents);
		data->singent = data->singent->next;
	}
}

void	print_entlst(t_data *data, int argc)
{
	while (data->entlst)
	{
		if (data->entlst->ents)
		{
			if (argc > 2 || data->cmds & CMD_R)
				ft_printf("%s:\n", data->entlst->path);
			print_ents(data->entlst->ents);
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
	get_stat(argc, argv, data);
	print_errlst(data->errors->nofile);
	print_singent(data);
	print_errlst(data->errors->pdeny);
	print_entlst(data, argc);
	return (0);
}



