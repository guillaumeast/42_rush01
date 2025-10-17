#include "rush01.h"

static t_bool	try_solve(t_run *run, size_t row, size_t col);
static t_bool	check_cell(t_map *map, size_t row, size_t col);
static t_bool	check_all(t_run *run);

void	solve(t_run *run)
{
	if (!run || !run->map)
		return ;
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
	while (i <= run->map->size)
	{
		run->map->content[row][col] = (int) i;
		if (check_cell(run->map, row, col) && try_solve(run, row, col + 1))
			return (TRUE);
		i++;
	}
	run->map->content[row][col] = 0;
	return (FALSE);
}

static t_bool	check_cell(t_map *map, size_t row, size_t col)
{
	size_t	i;

	i = 0;
	while (i < map->size)
	{
		if (i != col && map->content[row][i] == map->content[row][col])
			return (FALSE);
		if (i != row && map->content[i][col] == map->content[row][col])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	check_all(t_run *run)
{
	size_t	i;

	i = 0;
	while (i < run->map->size)
	{
		if (!check_colup(run, i) || !check_coldown(run, i))
			return (FALSE);
		if (!check_rowleft(run, i) || !check_rowright(run, i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
