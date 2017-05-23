/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:56:39 by rle               #+#    #+#             */
/*   Updated: 2017/05/23 15:22:09 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_err	*err_init(void)
{
	t_err *err;

	if (NULL == (err = (t_err *)malloc(sizeof(t_err))))
		return (NULL);
	err->ent = NULL;
	err->next = NULL;
	return (err);
}

void	add_err(t_err **err, char *ent)
{
	t_err *curr;

	curr = *err;
	if (!curr->ent)
	{
		curr->ent = ent;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	if (NULL == (curr->next = (t_err *)malloc(sizeof(t_err))))
		return (NULL);
	curr = curr->next;
	curr->ent = ent;
	curr->next = NULL;
}
char	*name_from_path(char *path)
{
	int i;
	int j;
	char *name;

	j = 0;
	i = 0;
	while (path[i])
		i++;
	while (path[i] != '/' && i >= 0)
	{
		j++;
		i++;
	}
	name = (char *)malloc(sizeof(char) * j + 1);
	j = 0;
	while (path[i])
		name[j++] = path[i++];
	name[j] = '\0';
	return (name);
}

t_errlst	*errlst_init(void)
{
	t_errlst *errlst;

	if (NULL == (errlst = (t_errlst *)malloc(sizeof(t_errlst))))
		return (NULL);
	errlst->name = NULL;
	errlst->msg = NULL;
	errlst->next = NULL;
}

char	*pdeny_msg(char *path, char *name)
{
	char *msg;

	msg = ft_strjoin(path, ":\n", 0);
	msg = ft_strjoin(msg, "./ft_ls: ", 1);
	msg = ft_strjoin(msg, name, 1);
	msg = ft_strjoin(msg, ": Permission denied\n", 1);
	return (msg);
}

void	add_pdeny(t_errlst *head, char *path)
{
	t_errlst	*curr;
	char		*name;

	name = name_from_path(path);
	curr = head;
	if (!curr->name)
	{
		curr->name = name;
		curr->msg = pdeny_msg(path, name);
	}
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = errlst_init();
		curr->name = name;
		curr->msg = pdeny_msg(path, name);
	}
}

char	*nofile_msg(char *name)
{
	char *msg;

	msg = ft_strjoin("./ft_ls: ", name);
	msg = ft_strjoin(msg, ": No such file or directory");
	return (msg);
}

void	add_nofile(t_errlst *head, char *name)
{
	t_errlst	*curr;
	char		*name;

	curr = head;
	if (!curr->name)
	{
		curr->name = name;
		curr->msg = nofile_msg(name);
	}
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = errlst_init();
		curr->name = name;
		curr->msg = nofile_msg(name);
	}
}























