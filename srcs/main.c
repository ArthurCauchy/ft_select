/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:40:51 by acauchy           #+#    #+#             */
/*   Updated: 2018/03/14 15:09:22 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*static int	my_putchar(int c)
{
	ft_putchar(c);
	return (0);
}*/

static void	mainloop(struct termios *orig_termios, t_termcaps **term)
{
	char	keybuff[4];
	int		read_size;
	int		arrowkey_code;

	while ((read_size = read(0, &keybuff, 3)) > 0)
	{
		keybuff[read_size] = '\0';
		if (!ft_isprint(keybuff[0]))
		{
			arrowkey_code = which_arrowkey(keybuff);
			if (arrowkey_code == 1)
				ft_putstr((*term)->goupstr);
			else if (arrowkey_code == 2)
				ft_putstr((*term)->godownstr);
			else if (arrowkey_code == 3)
				ft_putstr((*term)->gorightstr);
			else if (arrowkey_code == 4)
				ft_putstr((*term)->goleftstr);
			else if (keybuff[0] == 27)
				break ;
		}
		else
			ft_putstr(keybuff);
	}
	if (read_size == -1)
		exit_error(orig_termios, term, "read() error");
}

int			main(int argc, char **argv)
{
	struct termios	orig_termios;
	char			*termtype;
	int				success;
	t_termcaps		*term;

	(void)argc;
	(void)argv;
	term = NULL;
	enableRawMode(&orig_termios);
	termtype = getenv("TERM");
	if (!termtype)
		exit_error(&orig_termios, NULL, "TERM env variable is not set !");
	ft_fminiprint(1, "Term type : %l0s%\n", termtype);
	success = tgetent(NULL, termtype);
	if (success < 0)
		exit_error(&orig_termios, NULL, "Can't access the termcap database.");
	if (success == 0)
		exit_error(&orig_termios, NULL, "This terminal type is not defined.");
	init_termcap(&orig_termios, &term);
	mainloop(&orig_termios, &term);
	disable_raw_mode(&orig_termios);
	delete_termcap(&term);
	ft_putchar('\n');
	return (0);
}
