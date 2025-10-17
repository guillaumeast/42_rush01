#include "rush01.h"

static void	fix_min_cell(t_run *run, size_t row, size_t col);

void	fix_min(t_run *run)
{
	int	map_size;
	int	i;

	map_size = run->map->size;
	i = 0;
	while (i < map_size)
	{
		if (run->args->colup[i] == 1)
			fix_min_cell(run, 0, i);
		if (run->args->coldown[i] == 1)
			fix_min_cell(run, map_size - 1, i);
		if (run->args->rowleft[i] == 1)
			fix_min_cell(run, i, 0);
		if (run->args->rowright[i] == 1)
			fix_min_cell(run, i, map_size - 1);
		i++;
	}
}

static void	fix_min_cell(t_run *run, size_t row, size_t col)
{
	run->map->content[row][col] = run->map->size;
	run->map->fixed[row][col] = TRUE;
}
