/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:39:03 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/14 15:09:21 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_SELECT_H
# define __FT_SELECT_H

# include <stdio.h>

# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_termcaps
{
	char	*clearstr;
	char	*gotostr;
	char	*goupstr;
	char	*godownstr;
	char	*gorightstr;
	char	*goleftstr;
}				t_termcaps;

/*
** init.c
*/

void			init_termcap(struct termios *orig_termios, t_termcaps **term);
void			delete_termcap(t_termcaps **term);

/*
** utils.c
*/

void			exit_error(struct termios *orig_termios,
		t_termcaps **term, char *errmsg);
void			enable_raw_mode(struct termios *orig_termios);
void			disable_raw_mode(struct termios *orig_termios);

/*
** keyboard.c
*/

int				which_arrowkey(char *keybuff);

#endif
