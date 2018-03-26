void	draw_wordlist(void)
{
	t_wordlist	*cur;
	int					curr_col;

	cur = *get_wordlist();
	curr_col = 1;
	while (cur)
	{
		if (curr_col != 1)
			ft_putchar_fd(' ', (*get_term())->ttyfd);
		ft_putstr_fd(cur->word, (*get_term())->ttyfd);
		if ((curr_col == (*get_term())->display->col_per_line)
				&& cur->next)
		{
			ft_putchar_fd('\n', (*get_term())->ttyfd);
			curr_col = 1;
		}
		cur = cur->next;
	}
}

void	compute_cols(void)
{
	int	colsize;
	int	col_per_line;
	int	remaining;
	int lines;

	colsize = compute_col_size(get_wordlist());
	if (colsize > (*get_term())->nbcol)
	{
		col_per_line = 0;
		lines = 0;
	}
	else
	{
		col_per_line = 1;
		remaining = (*get_term())->nbcol - colsize;
		while (remaining >= colsize + 1)
		{
			remaining -= colsize + 1;
			++col_per_line;
		}
		lines = wordlist_count_word(*get_wordlist()) / col_per_line;
	}
	(*get_term)->display->col_per_line = col_per_line;
	(*get_term)->display->lines = lines;
}

// set meme quand on ret -1
// ca peut arive des pas avoir assez de lignes ????
