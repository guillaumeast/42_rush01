#include "rush01.h"

static t_run	*init_possibilities(t_run *run, t_cell *cell)
{
	size_t	i;
	int		value;

	cell->possible_size = run->map.size - 2;
	cell->possible_values = malloc(cell->possible_size * sizeof(int));
	if (!cell->possible_values)
		return (free_run(run));
	i = 0;
	value = 1;
	while (i < cell->possible_size)
		cell->possible_values[i++] = value++;
}

t_cell	*new_cell(t_run *run, int value)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	if (!cell)
		return (NULL);
	cell->value = value;
	if (cell->value == 0)
	{
		init_possibilities(run, cell);
		if (!run)
		{
			free(cell);
			return (NULL);
		}
	}
	else
	{
		cell->possible_size = 0;
		cell->possible_values = NULL;
	}
	return (cell);
}

void	set_value(t_cell *cell, int value)
{
	cell->value = value;
	if (cell->possible_values)
	{
		free(cell->possible_values);
		cell->possible_values = NULL;
	}
	cell->possible_size = 0;
}

t_run	*remove_possibilitie(t_run *run, t_cell *cell, int possibilitie)
{
	int		*new_values;
	size_t	i;
	size_t	j;

	// TODO: remove realloc for optimisation ?
	new_values = malloc((cell->possible_size - 1) * sizeof(int));
	if (!new_values)
		return (free_run(run));
	i = 0;
	j = 0;
	while (i < cell->possible_size)
	{
		if (cell->possible_values[i] != possibilitie)
			new_values[j++] = cell->possible_values[i];
		i++;
	}
	cell->possible_size--;
	free(cell->possible_values);
	cell->possible_values = new_values;
	return (run);
}

void	free_cell(t_cell *cell)
{
	if (!cell)
		return (NULL);
	if (cell->possible_values)
		free(cell->possible_values);
	free(cell);
	cell = NULL;
}
