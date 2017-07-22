/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:00:25 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:16:10 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	cut_time(char *time)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (time[i] != ' ')
		i++;
	i++;
	while (time[i] != ':')
		time[j++] = time[i++];
	time[j++] = ':';
	i++;
	while (time[i] != ':')
		time[j++] = time[i++];
	time[j] = '\0';
}

void	cut_big_t(char *time)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (time[i] != ' ')
		i++;
	while (time[++i])
		time[j++] = time[i];
	time[j] = '\0';
}

void	print_l(t_data *data, t_ent *head, t_sp spaces)
{
	char *tmp;

	if (!head->err)
	{
		ft_printf("%s", get_sperm(head->sb.st_mode));
		ft_printf(" %*ld ", spaces.links, ((long)head->sb.st_nlink));
		ft_printf("%s  ", head->pw->pw_name);
		ft_printf("%s ", head->grp->gr_name);
		ft_printf(" %*lld ", spaces.fl_sz, (long long)head->sb.st_size);
		tmp = ctime(&(head->sb).st_mtime);
		tmp[ft_strlen(tmp) - 1] = '\0';
		if (data->cmds & CMD_T)
			cut_big_t(tmp);
		else
			cut_time(tmp);
		ft_printf("%s %s\n", tmp, head->name);
	}
	else
		ft_printf("%s\n", head->err);
}
