/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   names_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 15:22:09 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:25:05 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

int	ft_timecmp(char *curr, char *name)
{
	struct stat sb1;
	struct stat sb2;

	if ((stat(name, &sb1)) < 0)
		return (-1);
	if ((stat(curr, &sb2)) < 0)
		return (-1);
	return (sb1.st_mtime - sb2.st_mtime);
}
