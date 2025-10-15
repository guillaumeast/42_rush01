#include "rush01.h"

static int	get_single_id(t_choices choices)
{
	size_t	i;

	i = 0;
	while (i < choices.size)
	{
		if (choices.tab[i] == 1)
			return (i);
		i++;
	}
	return (-1);
}

static t_cell	*find_in_row(t_run *run, size_t	y, size_t choice_index)
{
	size_t	x;

	x = 1;
	while (x < run->map.size - 1)
	{
		if (run->map.cells[y][x]->choices.tab[choice_index] == 1)
			return (run->map.cells[y][x]);
		x++;
	}
	return (NULL);
}

static t_cell	*find_in_col(t_run *run, size_t	x, size_t choice_index)
{
	size_t	y;

	y = 1;
	while (y < run->map.size - 1)
	{
		if (run->map.cells[y][x]->choices.tab[choice_index] == 1)
			return (run->map.cells[y][x]);
		y++;
	}
	return (NULL);
}

t_run	*check_row(t_run *run, size_t y)
{
	t_choices	choices;
	size_t		x;
	size_t		i;
	size_t		single_id;

	choices.size = run->map.size - 2;
	choices.tab = malloc(choices.size * sizeof(int));
	if (!choices.tab)
		return (free_run(run));
	i = 0;
	while (i < choices.size)
		choices.tab[i++] = 0;
	x = 0;
	while (x < choices.size)
	{
		i = 0;
		while (i < choices.size)
		{
			choices.tab[i] += run->map.cells[y][x]->choices.tab[i];
			i++;
		}
		x++;
	}
	single_id = get_single_id(choices);
	if (single_id >= 0)
		solve_cell(run, find_in_row(run, y, single_id), single_id + 1);
	return (run);
}
// TODO: 27 lignes !

t_run	*check_col(t_run *run, size_t x)
{
	t_choices	choices;
	size_t		y;
	size_t		i;
	size_t		single_id;

	choices.size = run->map.size - 2;
	choices.tab = malloc(choices.size * sizeof(int));
	if (!choices.tab)
		return (free_run(run));
	i = 0;
	while (i < choices.size)
		choices.tab[i++] = 0;
	y = 0;
	while (y < choices.size)
	{
		i = 0;
		while (i < choices.size)
		{
			choices.tab[i] += run->map.cells[y][x]->choices.tab[i];
			i++;
		}
		y++;
	}
	single_id = get_single_id(choices);
	if (single_id >= 0)
		solve_cell(run, find_in_col(run, x, single_id), single_id + 1);
	return (run);
}
// TODO: 27 lignes !
