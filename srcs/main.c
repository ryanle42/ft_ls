/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:07:42 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/20 14:54:09 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	read_file(char *path, char *name, t_data *data, t_files *files)
{
	struct stat sb;

	path = ft_strjoin(path, name);
	if (-1 == (stat(path, &sb)))
		add_err(&(data->err), name);
	else if (files == NULL)
	{
		if (-1 == add_file(path, name, data->files))
		{
			ft_printf("Error adding file\n");
			exit(1);
		}
	}
	else
	{
		if (-1 == add_file(path, name, files))
		{
			ft_printf("Error adding file\n");
			exit(1);
		}
	}
}

t_files		*files_init(void)
{
	t_files *files;

	if (NULL == (files = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	files->name = NULL;
	files->next = NULL;
	files->prev = NULL;
	return (files);
}

void	recursion(char *path, t_data *data)
{
	char *name;
	DIR *dirp;
	struct dirent *dp;
	t_files *files;

	if (NULL == (files = files_init()))
		return ;
	if (NULL != (dirp = opendir(path)))
	{
		ft_printf("%s:\n", path);
		path = ft_strjoin(path, "/");
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
				name = ft_strjoin(path, dp->d_name);
				recursion(name, data);
			}
		}
		closedir(dirp);
	}
}

void	get_stat(int argc, char **argv, t_data *data)
{
	int i;
	DIR *dirp;
	struct dirent *dp;
	char *path;
	char *name;
	t_files *files;

	i = 1;
	if (argc == 1)
	{
		path = "./";
		if (NULL == (dirp = opendir(".")))
		{
			ft_printf("Cannot open .");
			exit(1);
		}
		while (NULL != (dp = readdir(dirp)))
		{
			if (dp->d_name[0] != '.')
			{
				read_file(path, dp->d_name, data, NULL);
			}
		}
		closedir(dirp);
	}
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			path = ft_strjoin(argv[i], "/");
			if (NULL != (dirp = opendir(path)))
			{
				if (NULL == (files = files_init()))
						return ;
				ft_printf("%s:\n", argv[i]);
				while (NULL != (dp = readdir(dirp)))
				{
					if (dp->d_name[0] != '.')
					{
						name = ft_copystr(dp->d_name);
						read_file(path, name, data, files);
					}
				}
				print_files(files);
				free(files);
				closedir(dirp);
			}
			else
				read_file(".", argv[i], data, NULL);
			free(path);
		}
		i++;
	}
}

t_data	*data_init(void)
{
	t_data *data;

	if (NULL == (data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (NULL == (data->err = (t_err *)malloc(sizeof(t_err))))
		return (NULL);
	if (NULL == (data->files = files_init()))
		return (NULL);
	data->err->file = NULL;
	data->err->next = NULL;
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
	print_err(data->err);
	print_files(data->files);
	//recursion(".", data);
	//ft_printf("%s", data->pw->pw_name);
	return (1);
}



