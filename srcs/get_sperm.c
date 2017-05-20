/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sperm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:36:05 by rle               #+#    #+#             */
/*   Updated: 2017/05/20 13:52:17 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

static int filetypeletter(int mode)
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
#ifdef S_ISFIFO
	else if (S_ISFIFO(mode))
		c = 'p';
#endif
#ifdef S_ISLNK
	else if (S_ISLNK(mode))
		c = 'l';
#endif
#ifdef S_ISSOCK
	else if (S_ISSOCK(mode))
		c = 's';
#endif
#ifdef S_ISDOOR
	else if (S_ISDOOR(mode))
		c = 'D';
#endif
	else
		c = '?';
	return(c);
}

char *get_sperm(int mode)
{
	static const char *rwx[] = {"---", "--x", "-w-", "-wx",
	"r--", "r-x", "rw-", "rwx"};
	static char bits[11];

	bits[0] = filetypeletter(mode);
	ft_strcpy(&bits[1], rwx[(mode >> 6)& 7]);
	ft_strcpy(&bits[4], rwx[(mode >> 3)& 7]);
	ft_strcpy(&bits[7], rwx[(mode & 7)]);
	// if (mode & S_ISUID)
	// 	bits[3] = (mode & S_IXUSR) ? 's' : 'S';
	// if (mode & S_ISGID)
	// 	bits[6] = (mode & S_IXGRP) ? 's' : 'l';
	// if (mode & S_ISVTX)
	// 	bits[9] = (mode & S_IXOTH) ? 't' : 'T';
	bits[10] = '\0';
	return (bits);
}
