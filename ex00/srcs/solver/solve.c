#include "rush01.h"

static t_bool	try_solve(t_run *run, size_t row, size_t col);

void	solve(t_run *run)
{
	if (!run || !run->map)
		return ;
	fix_max(run);
	fix_min(run);
	run->map->is_complete = try_solve(run, 0, 0);
}

static t_bool	try_solve(t_run *run, size_t row, size_t col)
{
	size_t	i;

	if (col == run->map->size)
	{
		row++;
		col = 0;
	}
	if (row == run->map->size)
		return (check_all(run));
	i = 1;
	if (run->map->fixed[row][col])
		return (try_solve(run, row, col + 1));
	while (i <= run->map->size)
	{
		run->map->content[row][col] = (int) i;
		if (check_cell(run, row, col) && try_solve(run, row, col + 1))
			return (TRUE);
		i++;
	}
	run->map->content[row][col] = 0;
	return (FALSE);
}




