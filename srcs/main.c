/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:07:42 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/18 21:20:37 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	get_stat(int argc, char **argv, t_data *data)
{
	int i;
	struct stat sb;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			if (-1 == (stat(argv[i], &sb)))
			{
				add_err(&(data->err), argv[i++]);
				continue;
			}
			if (-1 == add_file(data, argv[i]))
			{
				ft_printf("Error adding file\n");
				exit(1);
			}
		}
		i++;
	}
}

t_data	*data_init(void)
{
	t_data *data;

	data = NULL;
	if (NULL == (data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->err = NULL;
	if (NULL == (data->err = (t_err *)malloc(sizeof(t_err))))
		return (NULL);
	data->files = NULL;
	if (NULL == (data->files = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	data->files->prev = NULL;
	data->files->next = NULL;
	data->files->name = NULL;
	data->err->file = NULL;
	data->err->next = NULL;
	data->total = 0;
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
	ft_printf("total %lli\n", data->total);
	print_files(data->files);
	//ft_printf("%s", data->pw->pw_name);
	return (1);
}



