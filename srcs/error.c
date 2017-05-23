/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:56:39 by rle               #+#    #+#             */
/*   Updated: 2017/05/22 20:57:03 by rle              ###   ########.fr       */
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

void	err(t_err *err, int errno)
{
	if (errno == 1)
		if (err->ent)
		{
			ft_printf("./ft_ls: %s: No such file or directory\n", err->ent);
			while (err->next)
			{
				err = err->next;
				ft_printf("./ft_ls: %s: No such file or directory\n", err->ent);
			}
		}
	if (errno == 2)
	{
		ft_printf("Error adding file\n");
		exit(1);
	}
}