#include "rush01.h"

// Caller must free
t_run	*new_run(int argc, char **argv)
{
	t_run	*run;
	size_t	i;

	run = malloc(sizeof(t_run));
	if (!run)
		return (NULL);
	run->args.size = argc - 1;
	run->args.values = malloc(run->args.size * sizeof(int));
	if (!run->args.values)
		return (free_run(run));
	i = 0;
	while (i < run->args.size)
	{
		run->args.values[i] = argv[i + 1][0] - '0';
		i++;
	}
	run->map.content = NULL;
	run->map.size = 0;
	return (run);
}

t_run	*free_run(t_run *run)
{
	if (!run)
		return (NULL);
	if (run->args.values)
		free(run->args.values);
	free_map(run);
	free(run);
	run = NULL;
	return (NULL);
}
