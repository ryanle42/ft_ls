/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 19:28:16 by anonymous         #+#    #+#             */
/*   Updated: 2017/05/17 09:37:21 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTLS_H
# define FTLS_H

# include <libft.h>


typedef struct		s_cmd
{
	int				l;
	int				R;
	int				r;
	int				a;
	int				t;
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

#endif
