#include "rush01.h"

t_bool	check_colup(t_run *run, size_t col)
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

t_bool	check_coldown(t_run *run, size_t col)
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

t_bool	check_rowleft(t_run *run, size_t row)
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

t_bool	check_rowright(t_run *run, size_t row)
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
