#include "rush01.h"

t_run	*solve_cell(t_run *run, t_cell *cell, int value)
{
	size_t	i;
	t_cell	*cell_h;
	t_cell	*cell_v;

	if (!run || !cell)
		return (free_run(run));
	if (cell->value != 0)
		return (run);
	set_value(cell, value);
	printf("\n||=> SOLVED: cell[%zu][%zu] = %d\n\n", cell->y, cell->x, cell->value);
	i = 1;
	while (run && i < run->map.size - 1)
	{
		cell_h = run->map.content[cell->y][i];
		run = remove_possibilitie(run, cell_h, value);
		if (run && cell_h->possible_size == 1)
			run = solve_cell(run, cell_h, cell_h->possible_values[0]);
		cell_v = run->map.content[i][cell->x];
		run = remove_possibilitie(run, cell_v, value);
		if (run && cell_v->possible_size == 1)
			run = solve_cell(run, cell_v, cell_v->possible_values[0]);
		i++;
	}
	return (run);
}

t_run	*solve(t_run *run)
{
	if (!run)
		return (NULL);
	run = resolve_minmax(run);
	// print_run(run);
	run = resolve_rows(run);
	print_run(run);
	return (run);
}
