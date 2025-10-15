#include "rush01.h"

static t_run	*minmax_colup(t_run *run)
{
	size_t	y;
	size_t	x;
	int		value;
	
	x = 1;
	while (run && x < run->map.size - 1)
	{
		if (run->map.content[0][x]->value == (int) run->map.size - 2)
		{
			y = 1;
			value = 1;
			while (run && y < run->map.size - 1)
			{
				run = solve_cell(run, run->map.content[y][x], value);
				y++;
				value++;
			}
		}
		else if (run->map.content[0][x]->value == 1)
			run = solve_cell(run, run->map.content[1][x], (int) run->map.size - 2);
		x++;
	}
	return (run);
}

static t_run	*minmax_coldown(t_run *run)
{
	size_t	y;
	size_t	x;
	int		value;
	
	x = 1;
	while (run && x < run->map.size - 1)
	{
		if (run->map.content[run->map.size - 1][x]->value == (int) run->map.size - 2)
		{
			y = 1;
			value = run->map.size - 2;
			while (run && y < run->map.size - 1)
			{
				run = solve_cell(run, run->map.content[y][x], value);
				y++;
				value--;
			}
		}
		else if (run->map.content[run->map.size - 1][x]->value == 1)
			run = solve_cell(run, run->map.content[run->map.size - 2][x], (int) run->map.size - 2);
		x++;
	}
	return (run);
}

static t_run	*minmax_rowleft(t_run *run)
{
	size_t	y;
	size_t	x;
	int		value;
	
	y = 1;
	while (run && y < run->map.size - 1)
	{
		if (run->map.content[y][0]->value == (int) run->map.size - 2)
		{
			x = 1;
			value = 1;
			while (run && x < run->map.size - 1)
			{
				run = solve_cell(run, run->map.content[y][x], value);
				x++;
				value++;
			}
		}
		else if (run->map.content[y][0]->value == 1)
			run = solve_cell(run, run->map.content[y][1], (int) run->map.size - 2);
		y++;
	}
	return (run);
}

static t_run	*minmax_rowright(t_run *run)
{
	size_t	y;
	size_t	x;
	int		value;
	
	y = 1;
	while (y < run->map.size - 1)
	{
		if (run->map.content[y][run->map.size - 1]->value == (int) run->map.size - 2)
		{
			x = 1;
			value = run->map.size - 2;
			while (run && x < run->map.size - 1)
			{
				run = solve_cell(run, run->map.content[y][x], value);
				x++;
				value--;
			}
		}
		else if (run && run->map.content[y][run->map.size - 1]->value == 1)
			run = solve_cell(run, run->map.content[y][run->map.size - 2], (int) run->map.size - 2);
		y++;
	}
	return (run);
}

t_run	*resolve_minmax(t_run *run)
{
	if (!run)
		return (NULL);
	run = minmax_colup(run);
	run = minmax_coldown(run);
	run = minmax_rowleft(run);
	run = minmax_rowright(run);
	return (run);
}
