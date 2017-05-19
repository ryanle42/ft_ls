/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:28:16 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/18 21:20:32 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <libft.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <pwd.h>

typedef struct			s_data
{
	int					cmds;
	long long			total;
	struct s_err		*err;
	struct s_files		*files;
}						t_data;

typedef struct			s_files
{
	char				*name;
	struct stat			sb;
	struct passwd		*pw;
	struct s_files		*next;
	struct s_files		*prev;
}						t_files;

enum				s_cmds
{
	CMD_l = 0x1,
	CMD_R = 0x2,
	CMD_r = 0x4,
	CMD_a = 0x8,
	CMD_t = 0x16,
	CMD_T = 0x32
};

typedef struct		s_err
{
	char			*file;
	struct s_err	*next;
}					t_err;

/*
**	get_commands
*/

int				get_commands(int argc, char **argv);

/*
**	error
*/
void			add_err(t_err **err, char *file);
void			print_err(t_err *err);


/*
**	files
*/
int				add_file(t_data *data, char *name);
void			print_files(t_files *head);

/*
struct passwd {
	char *pw_name;
	char *pw_passwd;
	uid_t pw_uid;
	gid_t pw_gid;
	time_t pw_change;
	char *pw_class;
	char *pw_gecos;
	char *pw_dir;
	char *pw_shell;
	time_t pw_expire;
}; 
*/

#endif
