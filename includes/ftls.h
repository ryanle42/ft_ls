/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:28:16 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/17 15:14:48 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <libft.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/xattr.h>
# include <pwd.h>

typedef struct		s_data
{
	struct s_cmd	*cmds;
	long long		total;
}					t_data;

typedef struct		s_cmd
{
	int				l;
	int				R;
	int				r;
	int				a;
	int				t;
	int				T;
}					t_cmd;

typedef struct		s_bdcmd
{
	char			cmd;
	struct s_bdcmd	*next;
}					t_bdcmd;

typedef struct		s_err
{
	struct s_bdcmd	*bdcmd;
}					t_err;

/*
**	get_commands
*/

t_cmd				*get_commands(int argc, char **argv);

#endif
