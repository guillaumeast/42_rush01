#include "rush01.h"

static void fix_colup(t_run *run, size_t col);
static void fix_coldown(t_run *run, size_t col);
static void fix_rowleft(t_run *run, size_t row);
static void fix_rowright(t_run *run, size_t row);

void	fix_max(t_run *run)
{
	int	map_size;
	int	i;

	map_size = (int) run->map->size;
	i = 0;
	while (i < map_size)
	{
		if (run->args->colup[i] == map_size)
			fix_colup(run, i);
		if (run->args->coldown[i] == map_size)
			fix_coldown(run, i);
		if (run->args->rowleft[i] == map_size)
			fix_rowleft(run, i);
		if (run->args->rowright[i] == map_size)
			fix_rowright(run, i);
		i++;
	}
}

static void fix_colup(t_run *run, size_t col)
{
	size_t	i;
	int		value;

	i = 0;
	value = 1;
	while (i < run->map->size)
	{
		run->map->content[i][col] = value;
		run->map->fixed[i][col] = TRUE;
		i++;
		value++;
	}
}

static void fix_coldown(t_run *run, size_t col)
{
	size_t	i;
	int		value;

	i = run->map->size;
	value = 1;
	while (i--)
	{
		run->map->content[i][col] = value;
		run->map->fixed[i][col] = TRUE;
		value++;
	}
}

static void fix_rowleft(t_run *run, size_t row)
{
	size_t	i;
	int		value;

	i = 0;
	value = 1;
	while (i < run->map->size)
	{
		run->map->content[row][i] = value;
		run->map->fixed[row][i] = TRUE;
		i++;
		value++;
	}
}

static void fix_rowright(t_run *run, size_t row)
{
	size_t	i;
	int		value;

	i = run->map->size;
	value = 1;
	while (i--)
	{
		run->map->content[row][i] = value;
		run->map->fixed[row][i] = TRUE;
		value++;
	}
}
