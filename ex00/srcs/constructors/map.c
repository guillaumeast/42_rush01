#include "rush01.h"

static t_bool	**init_fixed(size_t size);
static int		**init_content(size_t size);

t_map	*init_map(t_run *run)
{
	t_map	*map;

	if (!run)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->size = run->args->map_size;
	map->fixed = init_fixed(map->size);
	if (!map->fixed)
		return (NULL);
	map->content = init_content(map->size);
	if (!map->content)
		return (NULL);
	map->is_complete = FALSE;
	return (map);
}

void	free_map(t_map **map)
{
	size_t	i;

	if (!map || !*map)
		return ;
	if ((*map)->fixed)
	{
		i = 0;
		while (i < (*map)->size && (*map)->fixed[i])
			free((*map)->fixed[i++]);
		free((*map)->fixed);
	}
	if ((*map)->content)
	{
		i = 0;
		while (i < (*map)->size && (*map)->content[i])
			free((*map)->content[i++]);
		free((*map)->content);
	}
	free(*map);
	*map = NULL;
}

static t_bool	**init_fixed(size_t size)
{
	t_bool		**fixed;
	size_t		i;
	size_t		j;

	fixed = malloc(size * sizeof(t_bool *));
	if (!fixed)
		return (NULL);
	i = 0;
	while (i < size)
	{
		fixed[i] = malloc(size * sizeof(t_bool));
		if (!fixed[i])
		{
			while (i > 0)
				free(fixed[--i]);
			free(fixed);
			return (NULL);
		}
		j = 0;
		while (j < size)
			fixed[i][j++] = FALSE;
		i++;
	}
	return (fixed);
}

static int	**init_content(size_t size)
{
	int		**content;
	size_t	i;
	size_t	j;

	content = malloc(size * sizeof(int *));
	if (!content)
		return (NULL);
	i = 0;
	while (i < size)
	{
		content[i] = malloc(size * sizeof(int));
		if (!content[i])
		{
			while (i > 0)
				free(content[--i]);
			free(content);
			return (NULL);
		}
		j = 0;
		while (j < size)
			content[i][j++] = 0;
		i++;
	}
	return (content);
}
