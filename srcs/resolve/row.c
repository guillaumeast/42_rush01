#include "rush01.h"

static int	*malloc_counts(t_run *run)
{
	int		*counts;
	size_t	i;

	if (!run)
		return (NULL);
	counts = malloc((run->map.size - 2) * sizeof(int));
	if (!counts)
		return (NULL);
	i = 0;
	while (i < run->map.size - 2)
		counts[i++] = 0;
	return (counts);
}

static void	populate_counts(int	**counts, t_cell *cell)
{
	size_t	i;
	int		current;

	if (cell->possible_size == 0)
		return ;
	i = 0;
	while (i < cell->possible_size)
	{
		current = cell->possible_values[i];
		// printf("|---> cell[%zu][%zu]\n", cell->y, cell->x);
		// printf("|-> possibilities = ");
		// print_int_tab(cell->possible_values, cell->possible_size, 1);
		// printf("|-> current = %d\n", current);
		// printf("|-> counts[%d] = %d\n", current - 1, (*counts)[current - 1]);
		(*counts)[current - 1]++;
		// printf("|=> counts[%d] = %d\n", current - 1, (*counts)[current - 1]);
		i++;
	}
}

static int	get_single_id(int *counts, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (counts[i++] == 1)
			return (i);
	}
	return (-1);
}

t_run	*resolve_rows(t_run *run)
{
	int		*counts;
	size_t	y;

	if (!run)
		return (NULL);
	counts = malloc_counts(run);
	if (!counts)
		return (free_run(run));
	y = 1;
	while (run && y < run->map.size - 1)
		resolve_row(run, counts, y++);
	return (run);
}

t_run	*resolve_row(t_run *run, int *counts, int y)
{
	size_t	x;
	size_t	i;
	int		single_id;
	int		unique_possibilitie;

	if (!run || !counts)
		return (free_run(run));
	x = 1;
	while (x < run->map.size - 1)
		populate_counts(&counts, run->map.content[y][x++]);
	printf("-------ROW[%d]-------\n", y);
	printf("|-> counts = ");
	print_int_tab(counts, run->map.size - 2, 1);
	printf("---------------------\n\n");
	single_id = get_single_id(counts, run->map.size - 2);
	if (single_id == -1)
		return (run);
	unique_possibilitie = counts[single_id] + 1;
	x = 1;
	while (run && x < run->map.size - 1)
	{
		i = 0;
		while (run && run->map.content[y][x]->possible_size > 0 && i < run->map.size - 2)
		{
			if (run->map.content[y][x]->possible_values[i++] == unique_possibilitie)
			{
				run = solve_cell(run, run->map.content[y][x], unique_possibilitie);
			}
		}
		x++;
	}
	return (run);
}
