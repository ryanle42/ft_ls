/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listxfunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 12:16:17 by rle               #+#    #+#             */
/*   Updated: 2017/05/20 12:37:11 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftls.h>

void	get_listxattr(char *name)
{
	ssize_t	buflen;
	ssize_t	keylen;
	ssize_t	vallen;
	char	*buf;
	char	*key;
	char	*val;

	name = "author";
	if (-1 == (buflen = listxattr(name, NULL, 0, XATTR_NOFOLLOW)))
	{
		ft_printf("listxattr error.\n");
		exit(1);
	}
	if (buflen == 0)
		ft_printf("%s has no attributes.\n", name);
	buf = (char *)malloc(sizeof(char) * buflen);
	if (buf == NULL)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
	if (-1 == (buflen = listxattr(name, buf, buflen, XATTR_NOFOLLOW)))
	{
		ft_printf("listxattr error.\n");
		exit(1);
	}
	key = buf;
	while (buflen > 0)
	{
		ft_printf("%s: ", key);
		if (-1 == (vallen = getxattr(name, key, NULL, 0, 0, XATTR_NOFOLLOW)))
			ft_printf("getxattr error");
		if (vallen > 0)
		{
			if (NULL == (val = (char *)malloc(sizeof(char) * vallen + 1)))
			{
				ft_printf("malloc error");
				exit(1);
			}
			if (-1 == (vallen = getxattr(name, key, val, vallen, 0, XATTR_NOFOLLOW)))
				ft_printf("getxattr");
			else
			{
				val[vallen] = 0;
				ft_printf("%s", val);
			}
			free(val);
		}
		else if (vallen == 0)
			ft_printf("<no value>");
		ft_printf("\n");
		keylen = ft_strlen(key) + 1;
		buflen -= keylen;
		key += keylen;
	}
	free(buf);
}