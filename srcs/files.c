/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:19:50 by rle               #+#    #+#             */
/*   Updated: 2017/05/21 15:38:36 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

int	add_file(char *path, char *name, t_files *head)
{
	t_files *curr;
	t_files *prev;

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
	if (NULL == (curr->next = (t_files *)malloc(sizeof(t_files))))
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

void	calc_spaces(t_files *head, t_sp *spaces, long *total)
{
	spaces->fl_sz = 0;
	spaces->links = 0;

	*total = 0;
	while (head && head->name)
	{
		*total += head->sb.st_blocks;
		if (spaces->fl_sz < ft_int_length(head->sb.st_size))
			spaces->fl_sz = ft_int_length(head->sb.st_size);
		if (spaces->links < ft_int_length(head->sb.st_nlink))
			spaces->links = ft_int_length(head->sb.st_nlink);
		head = head->next;
	}
}


void	print_files(t_files *head)
{
	char *tmp;
	t_sp spaces;
	long total;

	calc_spaces(head, &spaces, &total);
	if (head->name)
		ft_printf("total %li\n", total);
	while (head && head->name)
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
		ft_printf("%s %s\n", tmp, head->name); // -t -l
		head = head->next;
	}
}
