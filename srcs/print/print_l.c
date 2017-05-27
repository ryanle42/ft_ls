/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:00:25 by rle               #+#    #+#             */
/*   Updated: 2017/05/26 16:31:55 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #include <ftls.h>

void	print_l(t_ent *head, t_sp spaces)
{
	char *tmp;

	ft_printf("%s", get_sperm(head->sb.st_mode));
	//get_listxattr(head->name);
	ft_printf(" %*ld ", spaces.links, ((long)head->sb.st_nlink));
	ft_printf("%s  ", head->pw->pw_name);
	ft_printf("%s ", head->grp->gr_name);
	ft_printf(" %*lld ", spaces.fl_sz, (long long)head->sb.st_size);
	//ft_printf("Last file access %s", ctime(&(head->sb)->st_atime)); // -u
	//if (cmds->l && cmds->T)
	tmp	= ctime(&(head->sb).st_atime);
	tmp[ft_strlen(tmp) - 1] = '\0';
	ft_printf("%s %s\n", tmp, head->name);
}