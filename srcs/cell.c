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
	return (run);
}

t_cell	*new_cell(t_run *run, size_t y, size_t x, int value)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	if (!run || !cell)
		return (NULL);
	cell->y = y;
	cell->x = x;
	cell->value = value;
	if (cell->value == 0)
	{
		run = init_possibilities(run, cell);
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
	if (cell->value != 0)
		return ;
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

	if (!run || cell->value != 0)
		return (run);
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
	printf("||===> REMOVED: cell[%zu][%zu] -= %d\n", cell->y, cell->x, possibilitie);
	return (run);
}

void	free_cell(t_cell *cell)
{
	if (!cell)
		return ;
	if (cell->possible_values)
		free(cell->possible_values);
	free(cell);
	cell = NULL;
}
