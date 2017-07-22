/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sperm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:36:05 by rle               #+#    #+#             */
/*   Updated: 2017/07/17 15:48:02 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static int	filetypeletter(int mode)
{
	char	c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}

char		*get_sperm(int mode)
{
	static const char	*rwx[] = {"---", "--x", "-w-", "-wx", \
	"r--", "r-x", "rw-", "rwx"};
	static char			bits[11];

	bits[0] = filetypeletter(mode);
	ft_strcpy(&bits[1], rwx[(mode >> 6) & 7]);
	ft_strcpy(&bits[4], rwx[(mode >> 3) & 7]);
	ft_strcpy(&bits[7], rwx[(mode & 7)]);
	bits[10] = '\0';
	return (bits);
}
