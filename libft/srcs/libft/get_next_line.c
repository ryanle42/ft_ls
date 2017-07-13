/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 13:30:02 by rle               #+#    #+#             */
/*   Updated: 2017/04/26 21:56:04 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file		*find_make_node(t_file *head, const int fd)
{
	t_file *current;

	current = head;
	while (current->next)
	{
		current = current->next;
		if (current->file == fd)
			return (current);
	}
	current->next = (t_file *)malloc(sizeof(t_file));
	current->next->file = fd;
	current->next->extra = (char *)malloc(sizeof(char) * 1);
	(current->next->extra)[0] = '\0';
	current->next->ret = 1;
	current->next->next = NULL;
	return (current->next);
}

int			check_extra(t_file *current, char **total, int *first, int i)
{
	char *tmp;

	if (!((current->extra)[0]))
	{
		(*total)[0] = '\0';
		if (current->ret == 0)
			return (1);
		return (0);
	}
	while ((current->extra)[++i])
	{
		if ((current->extra)[i] == '\n')
		{
			(*total)[i++] = '\0';
			tmp = current->extra;
			current->extra = ft_copystr(tmp + i);
			free(tmp);
			return (1);
		}
		(*total)[i] = (current->extra)[i];
	}
	(*total)[i] = '\0';
	*first = 2;
	return (0);
}

char		*buff_it(const int fd, t_file *current, int *first, int nl)
{
	char	buffer[BUFF_SIZE + 1];
	char	*total;
	int		i;

	total = ft_strnew(ft_strlen(current->extra));
	if (!(check_extra(current, &total, &(*first), -1)))
	{
		while (!nl && current->ret != 0)
		{
			i = 0;
			ft_memset(buffer, '\0', BUFF_SIZE + 1);
			if ((current->ret = read(fd, buffer, BUFF_SIZE)) < 0)
				return (NULL);
			((*first) == 1 && current->ret == 0) ? (*first--) : (*first = 2);
			while (buffer[i] && !nl)
				(buffer[i] == '\n') ? (nl = 1) : (i++);
			total = ft_strn_append(total, buffer, i);
		}
		free(current->extra);
		current->extra = ft_copystr(buffer + i + 1);
	}
	return (total);
}

int			get_next_line(const int fd, char **line)
{
	static t_file	*head;
	t_file			*current;
	int				first;

	first = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!head)
	{
		head = (t_file *)malloc(sizeof(t_file));
		head->next = NULL;
	}
	current = find_make_node(head, fd);
	*line = buff_it(fd, current, &first, 0);
	if (current->ret < 0)
		return (-1);
	if (current->ret > 0 || first == 2)
		return (1);
	return (0);
}
