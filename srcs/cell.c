#include "rush01.h"

static t_run	*init_choices(t_run *run, t_cell *cell)
{
	size_t	i;

	cell->choices.size = run->map.size - 2;
	cell->choices.tab = malloc(cell->choices.size * sizeof(int));
	if (!cell->choices.tab)
		return (free_run(run));
	i = 0;
	while (i < cell->choices.size)
		cell->choices.tab[i++] = 1;
	cell->choices.sum = i;
	return (run);
}

t_cell	*new_cell(t_run **run, size_t y, size_t x, int value)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	if (!cell)
		return (NULL);
	cell->y = y;
	cell->x = x;
	*run = init_choices(*run, cell);
	if (!*run)
		return (NULL);
	set_value(cell, value);
	return (cell);
}

void	set_value(t_cell *cell, int value)
{
	size_t	i;

	if (!cell)
		return ;
	cell->value = value;
	i = 0;
	if (cell->value != 0)
	{
		while (i < cell->choices.size)
			cell->choices.tab[i++] = 0;
		cell->choices.sum = 0;
	}
}

void	rm_choice(t_cell *cell, int choice)
{
	if (!cell || cell->choices.tab[choice - 1] == 0)
		return;
	cell->choices.tab[choice - 1] = 0;
	cell->choices.sum--;
}

void	free_cell(t_cell **cell)
{
	if (!(*cell))
		return ;
	if ((*cell)->choices.tab)
		free((*cell)->choices.tab);
	free(*cell);
	*cell = NULL;
}
