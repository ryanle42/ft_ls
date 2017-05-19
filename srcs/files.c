/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:19:50 by rle               #+#    #+#             */
/*   Updated: 2017/05/18 21:28:06 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

int	add_file(t_data *data, char *name)
{
	t_files *curr;
	t_files *prev;

	curr = data->files;
	if (!curr->name)
	{
		stat(name, &(curr->sb));
		if (NULL == (curr->pw = getpwuid(curr->sb.st_uid)))
			return (-1);
		curr->name = name;
		data->total += (long long)curr->sb.st_blocks;
		return (1);
	}
	while (curr->next)
		curr = curr->next;
	if (NULL == (curr->next = (t_files *)malloc(sizeof(t_files))))
		return (-1);
	prev = curr;
	curr = curr->next;
	curr->name = name;
	stat(name, &(curr->sb));
	if (NULL == (curr->pw = getpwuid(curr->sb.st_uid)))
		return (-1);
	curr->next = NULL;
	curr->prev = prev;
	data->total += (long long)curr->sb.st_blocks;
	return (1);
}

int	st_size_spaces(t_files *head)
{
	int largest;

	largest = 0;
	while (head && head->name)
	{
		if (largest < ft_int_length(head->sb.st_size))
			largest = ft_int_length(head->sb.st_size);
		head = head->next;
	}
	return (largest);
}

void	print_files(t_files *head)
{
	char *tmp;
	int st_size_sp;

	st_size_sp = st_size_spaces(head);
	while (head && head->name)
	{
		
		ft_printf("  %ld ", ((long)head->sb.st_nlink));
		ft_printf("%s ", head->pw->pw_name);
		ft_printf(" %*lld ", st_size_sp, (long long)head->sb.st_size);
		//ft_printf("Last file access %s", ctime(&(head->sb)->st_atime)); // -u
		//if (cmds->l && cmds->T)
		tmp	= ctime(&(head->sb).st_atime);
		tmp[ft_strlen(tmp) - 1] = '\0';
		ft_printf("%s %s\n", tmp, head->name); // -t -lT
		head = head->next;
	}
}
