/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 20:07:42 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/17 09:35:27 by anonymous        ###   ########.fr       */
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

t_cmd *get_commands(int argc, char **argv, t_err *err)
{
	t_cmd *cmds;
	int i;
	int j;

	cmds = (t_cmd*)malloc(sizeof(t_cmd));
	ft_bzero(cmds, sizeof(cmds));
	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][j])
			{
				if (argv[i][j] == 'l')
					cmds->l = 1;
				else if (argv[i][j] == 'R')
					cmds->R = 1;
				else if (argv[i][j] == 'r')
					cmds->r = 1;
				else if (argv[i][j] == 'a')
					cmds->a = 1;
				else if (argv[i][j] == 't')
					cmds->t = 1;
				else
					add_bd_cmd(&(err->bdcmd), argv[i][j]);
				j++;
			}
		}
		i++;
	}
	return (cmds);
}

int main(int argc, char **argv)
{
	t_cmd *cmds;
	t_err *err;

	err = err_init();
	cmds = get_commands(argc, argv, err);
	print_err(err);
	ft_printf("l:%i R:%i r:%i a:%i t:%i\n", cmds->l, cmds->R, cmds->r, cmds->a, cmds->t);
	return (1);
}