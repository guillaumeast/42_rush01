#include "rush01.h"

static t_run	*init_cells(t_run *run)
{
	size_t	i;
	size_t	j;

	run->map.cells = malloc(run->map.size * sizeof(t_cell **));
	if (!run->map.cells)
		return (free_run(run));
	i = 0;
	while (i < run->map.size)
	{
		run->map.cells[i] = malloc((run->map.size) * sizeof(t_cell *));
		if (!run->map.cells[i])
			return (free_run(run));
		j = 0;
		while (j < run->map.size)
		{
			run->map.cells[i][j] = new_cell(&run, i, j, 0);
			if (!run || !run->map.cells[i][j])
				return (free_run(run));
			j++;
		}
		i++;
	}
	return (run);
}

t_run	*init_map(t_run *run)
{
	size_t	i;
	size_t	j;

	if (!run)
		return (NULL);
	run->map.size = run->args.size / 4 + 2;
	run = init_cells(run);
	if (!run)
		return (NULL);
	j = 0;
	i = 1;
	while(i < run->map.size - 1)
		set_value(run->map.cells[0][i++], run->args.values[j++]);
	i = 1;
	while(i < run->map.size - 1)
		set_value(run->map.cells[run->map.size - 1][i++], run->args.values[j++]);
	i = 1;
	while (i < run->map.size - 1)
		set_value(run->map.cells[i++][0], run->args.values[j++]);
	i = 1;
	while(i < run->map.size - 1)
		set_value(run->map.cells[i++][run->map.size - 1], run->args.values[j++]);
	return (run);
}

void	free_map(t_run *run)
{
	size_t	i;
	size_t	j;

	if (!run || !run->map.cells)
		return ;
	i = 0;
	while (i < run->map.size && run->map.cells[i])
	{
		j = 0;
		while (j < run->map.size && run->map.cells[i][j])
			free_cell(&(run->map.cells[i][j++]));
		free(run->map.cells[i]);
		run->map.cells[i] = NULL;
		i++;
	}
	free(run->map.cells);
	run->map.cells = NULL;
	return ;
}
