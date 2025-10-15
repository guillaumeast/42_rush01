#include "rush01.h"

static void	update_cell(t_run *run, t_cell *cell, int choice_to_del)
{
	size_t	i;

	if (!cell || cell->value != 0)
		return;
	rm_choice(cell, choice_to_del);
	if (cell->choices.sum == 1)
	{
		i = 0;
		while (cell->choices.tab[i] == 0)
			i++;
		solve_cell(run, cell, i + 1);
	}
}

void	solve_cell(t_run *run, t_cell *cell, int value)
{
	size_t	i;

	if (!run || !cell || cell->value != 0)
		return ;
	set_value(cell, value);
	i = 1;
	while (i < run->map.size - 1)
	{
		update_cell(run, run->map.cells[cell->y][i], value);
		update_cell(run, run->map.cells[i][cell->x], value);
		i++;
	}
}
