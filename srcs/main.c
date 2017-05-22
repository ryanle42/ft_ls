/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:07:42 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/22 00:28:28 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	read_ent(char *path, char *name, t_data *data, t_ent *ents)
{
	struct stat sb;

	path = ft_strjoin(path, name, 0);
	if (-1 == (stat(path, &sb)))
		add_err(&(data->err), name);
	if (-1 == add_ent(path, name, ents))
		err(NULL, 2);
}

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
		if (NULL == (dirp = opendir(".")))
		{
			ft_printf("Cannot open .");
			exit(1);
		}
		if (NULL == (ents = ent_init()))
			return (-1);
		while (NULL != (dp = readdir(dirp)))
		{
			if (dp->d_name[0] != '.')
			{
				name = ft_copystr(dp->d_name);
				read_ent(".", name, data, ents);
			}
		}
		entlst_add_ents(data->entlst, ents);
		closedir(dirp);
	}
	while (++i < argc)
	{
		if (argv[i][0] != '-')
		{
			path = ft_strjoin(argv[i], "/", 0);
			if (NULL != (dirp = opendir(path)))
			{
				if (NULL == (ents = ent_init()))
						return (-1);
				if (argc > 2)
				{
					if (i != 1)
						ft_printf("\n");
					ft_printf("%s:\n", argv[i]);
				}
				while (NULL != (dp = readdir(dirp)))
				{
					if (dp->d_name[0] != '.')
					{
						name = ft_copystr(dp->d_name);
						read_ent(path, name, data, ents);
					}
				}
				entlst_add_ents(data->entlst, ents);
				closedir(dirp);
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
	if (NULL == (data->err = err_init()))
		return (NULL);
	if (NULL == (data->entlst = entlst_init()))
		return (NULL);
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

	get_stat(argc, argv, data);
	err(data->err, 1);
	print_ents(data->entlst->ents);

	// ft_printf("%s", data->pw->pw_name);
	return (1);
}



