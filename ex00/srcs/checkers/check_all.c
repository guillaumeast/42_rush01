#include "rush01.h"

static t_bool	check_colup(t_run *run, size_t col);
static t_bool	check_coldown(t_run *run, size_t col);
static t_bool	check_rowleft(t_run *run, size_t row);
static t_bool	check_rowright(t_run *run, size_t row);

t_bool	check_all(t_run *run)
{
	size_t	i;

	i = 0;
	while (i < run->map->size)
	{
		if (!check_colup(run, i) || !check_coldown(run, i))
			return (FALSE);
		if (!check_rowleft(run, i) || !check_rowright(run, i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	check_colup(t_run *run, size_t col)
{
	size_t	i;
	int		max;
	int		count;

	i = 0;
	max = 0;
	count = 0;
	while (i < run->map->size)
	{
		if (run->map->content[i][col] > max)
		{
			max = run->map->content[i][col];
			count++;
		}
		i++;
	}
	return (run->args->colup[col] == count);
}

static t_bool	check_coldown(t_run *run, size_t col)
{
	size_t	i;
	int		max;
	int		count;

	i = run->map->size;
	max = 0;
	count = 0;
	while (i--)
	{
		if (run->map->content[i][col] > max)
		{
			max = run->map->content[i][col];
			count++;
		}
	}
	return (run->args->coldown[col] == count);
}

static t_bool	check_rowleft(t_run *run, size_t row)
{
	size_t	i;
	int		max;
	int		count;

	i = 0;
	max = 0;
	count = 0;
	while (i < run->map->size)
	{
		if (run->map->content[row][i] > max)
		{
			max = run->map->content[row][i];
			count++;
		}
		i++;
	}
	return (run->args->rowleft[row] == count);
}

static t_bool	check_rowright(t_run *run, size_t row)
{
	size_t	i;
	int		max;
	int		count;

	i = run->map->size;
	max = 0;
	count = 0;
	while (i--)
	{
		if (run->map->content[row][i] > max)
		{
			max = run->map->content[row][i];
			count++;
		}
	}
	return (run->args->rowright[row] == count);
}
