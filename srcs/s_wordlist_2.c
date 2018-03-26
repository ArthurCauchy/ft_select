#include "ft_select.h"

int	wordlist_count_words(t_wordlist **wordlist)
{
	t_wordlist	*cur;
	int					count;

	cur = *wordlist;
	count = 0;
	while (cur)
	{
		cur = cur->next;
		++count;
	}
	return (count);
}
