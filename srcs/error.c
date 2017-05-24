/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:56:39 by rle               #+#    #+#             */
/*   Updated: 2017/05/23 20:34:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

t_error	*errors_init(void)
{
	t_error *error;

	if (NULL == (error = (t_error *)malloc(sizeof(t_error))))
		return (NULL);
	error->nofile = errlst_init();
	error->pdeny = errlst_init();
	return (error);
}

t_errlst	*errlst_init(void)
{
	t_errlst *errlst;

	if (NULL == (errlst = (t_errlst *)malloc(sizeof(t_errlst))))
		return (NULL);
	errlst->name = NULL;
	errlst->msg = NULL;
	errlst->next = NULL;
	return (errlst);
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
		curr = curr->next;
		curr->name = name;
		curr->msg = pdeny_msg(path, name);
	}
}

char	*nofile_msg(char *name)
{
	char *msg;

	msg = ft_strjoin("./ft_ls: ", name, 0);
	msg = ft_strjoin(msg, ": No such file or directory", 1);
	return (msg);
}

void	add_nofile(t_errlst *head, char *name)
{
	t_errlst	*curr;

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
		curr = curr->next;
		curr->name = name;
		curr->msg = nofile_msg(name);
	}
}

void	print_errlst(t_errlst *error)
{
	if (error && error->msg)
	{
		while (error && error->msg)
		{
			ft_printf("%s\n", error->msg);
			error = error->next;
		}
		ft_printf("\n");
	}
}