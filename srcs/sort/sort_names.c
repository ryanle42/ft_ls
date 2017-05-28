/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:31:55 by rle               #+#    #+#             */
/*   Updated: 2017/05/27 18:54:57 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	bubb_sort(int start, int max, char **argv)
{
	int i;
	int j;

	i = start;
	while (i < max)
	{
		j = start;
		while (j + 1 < max)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_strswap(&(argv[j]), &(argv[j + 1]));
			j++;
		}
		i++;
	}
}

void	sort_names(int i, int max, char **argv)
{
	while (i < max && argv[i][0] == '-')
		i++;
	bubb_sort(i, max, argv);
}