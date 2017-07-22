/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:31:55 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:17:58 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	bubb_sort(t_data *data, int start, int max, char **argv)
{
	int i;
	int j;

	i = start;
	while (i < max)
	{
		j = start;
		while (j + 1 < max)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0 && !(data->cmds & CMD_r))
				ft_strswap(&(argv[j]), &(argv[j + 1]));
			else if (ft_strcmp(argv[j], argv[j + 1]) < 0 && data->cmds & CMD_r)
				ft_strswap(&(argv[j]), &(argv[j + 1]));
			j++;
		}
		i++;
	}
}

int		sort_names(t_data *data, int max, char **argv)
{
	int start;

	start = 1;
	while (start < max && argv[start][0] == '-')
		start++;
	bubb_sort(data, start, max, argv);
	return (start);
}
