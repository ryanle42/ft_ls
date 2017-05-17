/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:07:42 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/17 16:03:22 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	add_bd_cmd(t_bdcmd **head, char cmd)
{
	t_bdcmd *curr;

	if (!(*head))
	{
		(*head) = (t_bdcmd *)malloc(sizeof(t_bdcmd));
		(*head)->cmd = cmd;
		(*head)->next = NULL;
	}
	else
	{
		curr = *head;
		if (curr->cmd == cmd)
				return ;
		while (curr->next)
		{
			if (curr->cmd == cmd)
				return ;
			curr = curr->next;
		}
		if (curr->cmd == cmd)
			return ;
		curr->next = (t_bdcmd *)malloc(sizeof(t_bdcmd));
		curr->next->cmd = cmd;
		curr->next->next = NULL;
	}
}

void	print_err(t_err *err)
{
	while (err->bdcmd)
	{
		ft_printf("ft_ls: invalid option -- \'%c\'\n", err->bdcmd->cmd);
		err->bdcmd = err->bdcmd->next;
	}
}

t_err *err_init(void)
{
	t_err *err;

	err = (t_err *)malloc(sizeof(t_err));
	err->bdcmd = NULL;
	return (err);
}

void	get_stat(int argc, char **argv, struct stat *sb, t_data *data)
{
	int i;
	char *tmp;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			if (-1 == (stat(argv[i], &(*sb))))
			{
				ft_printf("./ft_ls: %s: No such file or directory\n", argv[i]);
				exit(1);
			}
			ft_printf("  %ld  ",(long)sb->st_nlink);
			ft_printf("%ld\t", (long)sb->st_uid);
			ft_printf("%lld ", (long long)sb->st_size);
			data->total += (long long)sb->st_blocks;
			//ft_printf("Last file access:         %s", ctime(&sb->st_atime)); // -u
			//if (cmds->l && cmds->T)
			tmp	= ctime(&sb->st_mtime);
			tmp[ft_strlen(tmp) - 1] = '\0';
				ft_printf("%s %s\n", tmp, argv[i]); // -t -lT
		}
		i++;
	}
}

t_data	*data_init(void)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->cmds = NULL;
	data->total = 0;
	return (data);
}

int main(int argc, char **argv)
{
	t_data *data;
	t_err *err;
	struct stat sb;

	data = data_init();
	err = err_init();
	data->cmds = get_commands(argc, argv);
	get_stat(argc, argv, &sb, data);
	print_err(err);
	ft_printf("total: %lli\n", data->total);
	return (1);
}



