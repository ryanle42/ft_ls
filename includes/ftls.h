/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:28:16 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/23 21:11:14 by anonymous        ###   ########.fr       */
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
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct			s_data
{
	int					cmds;
	struct s_error		*errors;
	struct s_entlst		*singent;
	struct s_entlst		*entlst;
}						t_data;

typedef struct			s_entlst
{
	char				*path;
	struct s_entlst		*next;
	struct s_ent		*ents;
}						t_entlst;

typedef struct			s_ent
{
	char				*name;
	struct stat			sb;
	struct passwd		*pw;
	struct s_ent		*next;
	struct s_ent		*prev;
}						t_ent;

typedef struct			s_error
{
	struct s_errlst		*nofile;
	struct s_errlst		*pdeny;
}						t_error;

typedef struct			s_errlst
{	
	char				*name;
	char				*msg;
	struct s_errlst		*next;
}						t_errlst;

typedef struct			s_sp
{
	int					fl_sz;
	int					links;
}						t_sp;

enum					s_cmds
{
	CMD_l = 1,
	CMD_R = 2,
	CMD_r = 4,
	CMD_a = 8,
	CMD_t = 16,
	CMD_T = 32
};

/*
**	get_commands
*/

int						get_commands(int argc, char **argv);

/*
**	helpers
*/
char					*name_from_path(char *path);
char					*get_fpath(char *path, char *name);
void					read_ent(char *path, char *name, t_data *data, t_ent *ents);

/*
**	error
*/
t_error					*errors_init(void);
t_errlst				*errlst_init(void);
void					add_pdeny(t_errlst *head, char *path);
void					add_nofile(t_errlst *head, char *name);
void					print_errlst(t_errlst *error);

/*
**	ent
*/
t_ent					*ent_init(void);
int						add_ent(char *path, char *name, t_ent *head);
void					print_ents(t_ent *head);

/*
**	listxattr
*/

/*
**	get_sperm
*/
char					*get_sperm(int mode);


/*
**	entlst
*/
t_entlst				*entlst_init(void);
void					entlst_add_ents(t_entlst *entlst, t_ent *ents, char *path);

/*
**	recursion
*/
void					recursion(char *path, t_data *data);

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
