/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ents.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:58:21 by rle               #+#    #+#             */
/*   Updated: 2017/07/21 17:43:12 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static void	print_ents_help(t_ent *head, t_sp spaces, int i)
{
	if (i % 6 == 0 || !head->prev)
		if (head->err)
			ft_printf("%s", head->err);
		else
			ft_printf("%s", head->name);
	else
		ft_printf("%*s", 2 + spaces.name - (int)ft_strlen(head->prev->name) \
			+ (int)ft_strlen(head->name), head->name);
	if (i > 0 && ((i + 1) % 6 == 0) && head->next)
		ft_printf("\n");
}

static void	print_r_ents_help(t_ent *head, t_sp spaces, int i)
{
	if (i % 6 == 0 || !head->next)
		ft_printf("%s", head->name);
	else
		ft_printf("%*s", 2 + spaces.name - (int)ft_strlen(head->next->name) \
			+ (int)ft_strlen(head->name), head->name);
	if (i > 0 && ((i + 1) % 6 == 0) && head->prev)
		ft_printf("\n");
}

void		print_ents(t_ent *head, t_data *data)
{
	t_sp	spaces;
	int		i;
	t_ent	*curr;

	i = 0;
	if (head && (head->name))
		calc_spaces(head, &spaces);
	else
		return ;
	while (head && (head->name))
	{
		if (data->cmds & CMD_l)
			print_l(data, head, spaces);
		else
			print_ents_help(head, spaces, i);
		i++;
		curr = head->next;
		head = curr;
	}
	if (!(data->cmds & CMD_l))
		ft_printf("\n");
}

void		print_r_ents(t_ent *head, t_data *data)
{
	t_sp	spaces;
	int		i;

	i = 0;
	if (head && head->name)
		calc_spaces(head, &spaces);
	else
		return ;
	while (head->next && head->next->name)
		head = head->next;
	while (head && head->name)
	{
		if (data->cmds & CMD_l)
			print_l(data, head, spaces);
		else
			print_r_ents_help(head, spaces, i);
		i++;
		head = head->prev;
	}
	if (!(data->cmds & CMD_l))
		ft_printf("\n");
}
