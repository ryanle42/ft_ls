/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:02:12 by rle               #+#    #+#             */
/*   Updated: 2017/05/18 19:05:21 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

/*
static t_cmd	*cmd_init(void)
{
	t_cmd *cmds;

	cmds = (t_cmd*)malloc(sizeof(t_cmd));
	cmds->l = 0;
	cmds->R = 0;
	cmds->r = 0;
	cmds->a = 0;
	cmds->t = 0;
	return (cmds);
}
*/
static int		set_cmd(int *cmds, char cmd)
{
	if (cmd == 'l')
		(*cmds) |= CMD_l;
	else if (cmd == 'R')
		(*cmds) |= CMD_R;
	else if (cmd == 'r')
		(*cmds) |= CMD_r;
	else if (cmd == 'a')
		(*cmds) |= CMD_a;
	else if (cmd == 't')
		(*cmds) |= CMD_t;
	else if (cmd == 'T')
		(*cmds) |= CMD_T;
	else
		return (-1);
	return (1);
}

int			get_commands(int argc, char **argv)
{
	//t_cmd *cmds;
	int cmds;
	int i;
	int j;

	//cmds = cmd_init();
	cmds = 0;
	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][j])
			{
				if (-1 == (set_cmd(&cmds, argv[i][j])))
				{
					ft_printf("./ft_ls: illegal option -- %c\n", argv[i][j]);
					ft_printf("usage: ./ft_ls [-Ralrt] [file ...]\n");
					exit(1);
				}
				j++;
			}
		}
		i++;
	}
	return (cmds);
}
