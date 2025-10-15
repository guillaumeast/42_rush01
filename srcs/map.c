#include "rush01.h"

static t_run	*init_content(t_run *run)
{
	size_t	i;
	size_t	j;

	run->map.content = malloc(run->map.size * sizeof(t_cell **));
	if (!run->map.content)
		return (free_run(run));
	i = 0;
	while (i < run->map.size)
	{
		run->map.content[i] = malloc((run->map.size) * sizeof(t_cell *));
		if (!run->map.content[i])
			return (free_run(run));
		j = 0;
		while (j < run->map.size)
		{
			run->map.content[i][j] = new_cell(run, 0);
			if (!run->map.content[i][j])
				return (free_run(run));
			j++;
		}
		i++;
	}
	return (run);
}

t_run	*init_map(t_run *run)
{
	size_t	i;
	size_t	j;

	if (!run)
		return (NULL);
	run->map.size = run->args.size / 4 + 2;
	run = init_content(run);
	if (!run)
		return (NULL);
	j = 0;
	i = 1;
	while(i < run->map.size - 1)
		set_value(run->map.content[0][i++], run->args.values[j++]);
	i = 1;
	while(i < run->map.size - 1)
		set_value(run->map.content[run->map.size - 1][i++], run->args.values[j++]);
	i = 1;
	while (i < run->map.size - 1)
		set_value(run->map.content[i++][0], run->args.values[j++]);
	i = 1;
	while(i < run->map.size - 1)
		set_value(run->map.content[i++][run->map.size - 1], run->args.values[j++]);
	return (run);
}

void	free_map(t_run *run)
{
	size_t	i;
	size_t	j;

	if (!run || !run->map.content)
		return ;
	i = 0;
	while (i < run->map.size && run->map.content[i])
	{
		j = 0;
		while (j < run->map.size && run->map.content[i][j])
			free_cell(run->map.content[i][j++]);
		free(run->map.content[i]);
		run->map.content[i] = NULL;
		i++;
	}
	free(run->map.content);
	run->map.content = NULL;
	return ;
}
