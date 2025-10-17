#include "rush01.h"

static t_bool	check_colup_so_far(t_run *run, size_t col);
static t_bool	check_coldown_so_far(t_run *run, size_t col);
static t_bool	check_rowleft_so_far(t_run *run, size_t row);
static t_bool	check_rowright_so_far(t_run *run, size_t row);

t_bool	check_cell(t_run *run, size_t row, size_t col)
{
	size_t	i;

	i = 0;
	while (i < run->map->size)
	{
		if (i != col && run->map->content[row][i] == run->map->content[row][col])
			return (FALSE);
		if (i != row && run->map->content[i][col] == run->map->content[row][col])
			return (FALSE);
		i++;
	}
	if (!check_colup_so_far(run, col))
		return (FALSE);
	if (!check_coldown_so_far(run, col))
		return (FALSE);
	if (!check_rowleft_so_far(run, row))
		return (FALSE);
	if (!check_rowright_so_far(run, row))
		return (FALSE);
	return (TRUE);
}

static t_bool	check_colup_so_far(t_run *run, size_t col)
{
	size_t	i;
	int		count;
	int		max;
	int		free_cells;

	i = 0;
	count = 0;
	max = 0;
	free_cells = 0;
	while (i < run->map->size)
	{
		if (run->map->content[i][col] == 0)
			free_cells++;
		if (run->map->content[i][col] > max)
		{
			max = run->map->content[i][col];
			count++;
		}
		i++;
	}
	if (count > run->args->colup[col])
		return (FALSE);
	if (count + free_cells < run->args->colup[col])
		return (FALSE);
	return (free_cells != 0 || count == run->args->colup[col]);
}

static t_bool	check_coldown_so_far(t_run *run, size_t col)
{
	size_t	i;
	int		count;
	int		max;
	int		free_cells;

	i = run->map->size;
	count = 0;
	max = 0;
	free_cells = 0;
	while (i--)
	{
		if (run->map->content[i][col] == 0)
			free_cells++;
		if (run->map->content[i][col] > max)
		{
			max = run->map->content[i][col];
			count++;
		}
	}
	if (count > run->args->coldown[col])
		return (FALSE);
	if (count + free_cells < run->args->coldown[col])
		return (FALSE);
	return (free_cells != 0 || count == run->args->coldown[col]);
}

static t_bool	check_rowleft_so_far(t_run *run, size_t row)
{
	size_t	i;
	int		count;
	int		max;
	int		free_cells;

	i = 0;
	count = 0;
	max = 0;
	free_cells = 0;
	while (i < run->map->size)
	{
		if (run->map->content[row][i] == 0)
			free_cells++;
		if (run->map->content[row][i] > max)
		{
			max = run->map->content[row][i];
			count++;
		}
		i++;
	}
	if (count > run->args->rowleft[row])
		return (FALSE);
	if (count + free_cells < run->args->rowleft[row])
		return (FALSE);
	return (free_cells != 0 || count == run->args->rowleft[row]);
}

static t_bool	check_rowright_so_far(t_run *run, size_t row)
{
	size_t	i;
	int		count;
	int		max;
	int		free_cells;

	i = run->map->size;
	count = 0;
	max = 0;
	free_cells = 0;
	while (i--)
	{
		if (run->map->content[row][i] == 0)
			free_cells++;
		if (run->map->content[row][i] > max)
		{
			max = run->map->content[row][i];
			count++;
		}
	}
	if (count > run->args->rowright[row])
		return (FALSE);
	if (count + free_cells < run->args->rowright[row])
		return (FALSE);
	return (free_cells != 0 || count == run->args->rowright[row]);
}
