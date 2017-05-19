/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 19:56:39 by rle               #+#    #+#             */
/*   Updated: 2017/05/18 20:01:13 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	add_err(t_err **err, char *file)
{
	t_err *curr;

	curr = *err;
	if (!curr->file)
	{
		curr->file = file;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = (t_err *)malloc(sizeof(t_err));
	curr = curr->next;
	curr->file = file;
	curr->next = NULL;
}

void	print_err(t_err *err)
{
	if (err->file)
	{
		ft_printf("./ft_ls: %s: No such file or directory\n", err->file);
		while (err->next)
		{
			err = err->next;
			ft_printf("./ft_ls: %s: No such file or directory\n", err->file);
		}
	}
}
