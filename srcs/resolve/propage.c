#include "rush01.h"

t_run	*solve_cell(t_run *run, t_cell *cell, int value)
{
	size_t	i;

	if (!run || !cell)
		return (free_run(run));
	if (cell->value != 0)
		return (run);
	printf("solve_cell => [%zu][%zu] = %d", cell->y, cell->x, value);
	set_value(cell, value);
	i = 1;
	while (run && i < run->map.size - 1)
	{
		run = remove_possibilitie(run, run->map.content[cell->y][i], value);
		if (run && run->map.content[cell->y][i]->possible_size == 1)
			run = solve_cell(run, run->map.content[cell->y][i], run->map.content[cell->y][i]->possible_values[0]);
		run = remove_possibilitie(run, run->map.content[i][cell->x], value);
		if (run && run->map.content[i][cell->x]->possible_size == 1)
			run = solve_cell(run, run->map.content[i][cell->x], run->map.content[i][cell->x]->possible_values[0]);
		i++;
	}
	return (run);
}

// TODO: case 1 => une seule possibilité restante (eg solve_singles)
// TODO: case 2 => seule possibilité pour ce nombre dans la ligne ou colonne

t_run	*solve_bis(t_run run)
{
	// int	*check
	// int	
	// check = malloc((run->map.size - 2) * sizeof(int)) |=> Array to keep track of how many time each possibilitie has been seen
	// Initialiser check à 0 partout
	// Parcourir une ligne ou colonne et update check (if cell->possibilities contains 3 => check[2]++)
	// Après avoir terminé la ligne / colonne => Vérifier si check contient un 1
	//	|=> Si oui, solve_cell
}

// TODO : count unsolved (if unsolved == 0 => return, solving is ended)
t_run	*solve_singles(t_run *run)
{
	size_t	y;
	size_t	x;
	int		updated;

	updated = 1;
	while (run && updated != 0)
	{
		updated = 0;
		y = 1;
		while (run && y < run->map.size - 1)
		{
			x = 1;
			while (run && x < run->map.size - 1)
			{
				if (run->map.content[y][x]->possible_size == 1)
				{
					run = solve_cell(run, run->map.content[y][x], run->map.content[y][x]->possible_values[0]);
					updated++;
				}
				x++;
			}
			y++;
		}
	}
	return (run);
}

t_run	*solve(t_run *run)
{
	if (!run)
		return (NULL);
	run = resolve_minmax(run);
	print_run(run, "BEFORE solve_singles");
	run = solve_singles(run);
	print_run(run, "AFTER solve_singles");
	return (run);
}
