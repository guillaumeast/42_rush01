#include "rush01.h"

t_run	*solve(t_run *run)
{
	size_t	i;

	if (!run)
		return (NULL);
	run = resolve_minmax(run);
	print_run(run);
	i = 1;
	while (i < run->map.size - 1)
		run = check_row(run, i++);
	print_run(run);
	i = 1;
	while (i < run->map.size - 1)
		run = check_col(run, i++);
	print_run(run);
	return (run);
}
