/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:02:12 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:48:11 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

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

int				get_commands(int argc, char **argv)
{
	int cmds;
	int i;
	int j;

	cmds = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		j = 1;
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
		i++;
	}
	return (cmds);
}
