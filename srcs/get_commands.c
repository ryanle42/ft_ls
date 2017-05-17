/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:02:12 by rle               #+#    #+#             */
/*   Updated: 2017/05/17 14:27:51 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

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

static int		set_cmd(t_cmd *cmds, char cmd)
{
	if (cmd == 'l')
		cmds->l = 1;
	else if (cmd == 'R')
		cmds->R = 1;
	else if (cmd == 'r')
		cmds->r = 1;
	else if (cmd == 'a')
		cmds->a = 1;
	else if (cmd == 't')
		cmds->t = 1;
	else if (cmd == 'T')
		cmds->T = 1;
	else
		return (-1);
	return (1);
}

t_cmd			*get_commands(int argc, char **argv)
{
	t_cmd *cmds;
	int i;
	int j;

	cmds = cmd_init();
	i = 1;
	while (i < argc)
	{
		j = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][j])
			{
				if (-1 == (set_cmd(cmds, argv[i][j])))
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
