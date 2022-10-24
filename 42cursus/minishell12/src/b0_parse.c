#include "minishell.h"


int parse_structure(t_mp *mp, t_r *runnable);
int split_into_excutables(t_mp *mp, t_r *runnable);
int parse_excutables_text(t_r *runnable);
int expansion(t_mp *mp, t_r *runnable);


void parse(t_mp *mp, t_r *runnable)
{
	print_runnable(runnable, "before parse");

	split_into_excutables(mp, runnable);
	print_runnable(runnable, "after split_into_excutables");

	parse_excutables_text(runnable);
	print_runnable(runnable, "after parse_excutables_text");

	expansion(mp, runnable);
	print_runnable(runnable, "after expansion");

}

