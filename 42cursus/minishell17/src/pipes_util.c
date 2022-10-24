#include "minishell.h"

int	is_ltoken(t_list *rd)
{
	while (rd)
	{
		if (rd->content->type == 'l')
			return (0);
		rd = rd->next;
	}
	return (1);
}

int	is_rtoken(t_list *rd)
{
	while (rd)
	{
		if (rd->content->type == 'r')
			return (0);
		rd = rd->next;
	}
	return (1);
}
