/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ent.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:19:50 by rle               #+#    #+#             */
/*   Updated: 2017/05/24 16:54:27 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_ent		*ent_init(void)
{
	t_ent *ent;

	if (NULL == (ent = (t_ent *)malloc(sizeof(t_ent))))
		return (NULL);
	ent->name = NULL;
	ent->next = NULL;
	ent->prev = NULL;
	return (ent);
}

int	add_ent(char *path, char *name, t_ent *head)
{
	t_ent *curr;
	t_ent *prev;

	curr = head;
	if (!curr->name)
	{
		stat(path, &(curr->sb));
		if (NULL == (curr->pw = getpwuid(curr->sb.st_uid)))
			return (-1);
		curr->name = name;
		return (1);
	}
	while (curr->next)
		curr = curr->next;
	if (NULL == (curr->next = (t_ent *)malloc(sizeof(t_ent))))
		return (-1);
	prev = curr;
	curr = curr->next;
	curr->name = name;
	stat(path, &(curr->sb));
	if (NULL == (curr->pw = getpwuid(curr->sb.st_uid)))
		return (-1);
	curr->next = NULL;
	curr->prev = prev;
	return (1);
}

void	calc_spaces(t_ent *head, t_sp *spaces)
{
	spaces->fl_sz = 0;
	spaces->links = 0;
	spaces->name = 0;
	spaces->files = 0;

	while (head && head->name)
	{
		if (spaces->fl_sz < ft_int_length(head->sb.st_size))
			spaces->fl_sz = ft_int_length(head->sb.st_size);
		if (spaces->links < ft_int_length(head->sb.st_nlink))
			spaces->links = ft_int_length(head->sb.st_nlink);
		if (spaces->name < (int)ft_strlen(head->name))
			spaces->name = (int)ft_strlen(head->name);
		spaces->files++;
		head = head->next;
	}
}

void	print_ents(t_ent *head, t_data *data)
{
	char *tmp;
	t_sp spaces;

	int i;
	i = 0;
	if (head && head->name)
		calc_spaces(head, &spaces);
	while (head && head->name)
	{
		if (data->cmds & CMD_l)
		{
			ft_printf("%s", get_sperm(head->sb.st_mode));
			//get_listxattr(head->name);
			ft_printf(" %*ld ", spaces.links, ((long)head->sb.st_nlink));
			ft_printf("%s ", head->pw->pw_name);
			ft_printf(" %*lld ", spaces.fl_sz, (long long)head->sb.st_size);
			//ft_printf("Last file access %s", ctime(&(head->sb)->st_atime)); // -u
			//if (cmds->l && cmds->T)
			tmp	= ctime(&(head->sb).st_atime);
			tmp[ft_strlen(tmp) - 1] = '\0';
			ft_printf("%s ", tmp);
		}
		else
		{
			if (i % 6 == 0 || !head->prev)
				ft_printf("%s", head->name);
			else
				ft_printf("%*s", 2 + spaces.name - (int)ft_strlen(head->prev->name) + (int)ft_strlen(head->name), head->name); // -t -l
			if (i > 0 && ((i + 1) % 6 == 0))
				ft_printf("\n");
		}
		i++;
		head = head->next;
	}
	if (i != 0 && !(data->cmds & CMD_l))
		ft_printf("\n");
}
