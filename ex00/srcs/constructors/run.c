#include "rush01.h"

t_run	*init_run()
{
	t_run	*run;

	run = malloc(sizeof(t_run));
	if (!run)
		return (NULL);
	run->args = NULL;
	run->map = NULL;
	return (run);
}

void	free_run(t_run **run)
{
	if (!run || !*run)
		return;
	if ((*run)->args)
		free_args(&(*run)->args);
	// if ((*run)->map)
	// 	free_map(&(*run)->map);
	free(*run);
	*run = NULL;
}
