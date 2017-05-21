/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle <rle@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:28:16 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/21 15:35:27 by rle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <libft.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>

typedef struct			s_data
{
	int					cmds;
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

typedef struct			s_sp
{
	int					fl_sz;
	int					links;
}						t_sp;

enum				s_cmds
{
	CMD_l = 1,
	CMD_R = 2,
	CMD_r = 4,
	CMD_a = 8,
	CMD_t = 16,
	CMD_T = 32
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
int				add_file(char *path, char *name, t_files *head);
void			print_files(t_files *head);

/*
**	listxattr
*/
void			get_listxattr(char *name);

/*
**	get_sperm
*/
char			*get_sperm(int mode);

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
