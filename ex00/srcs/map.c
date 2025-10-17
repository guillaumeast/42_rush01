#include "rush01.h"

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

t_map	*init_map(t_run *run)
{
	t_map	*map;

	if (!run)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->size = run->args->map_size;
	map->content = init_content(map->size);
	if (!map->content)
		return (NULL);
	map->is_complete = FALSE;
	return (map);
}

void	free_map(t_map **map)
{
	size_t	i;

	if (!*map)
		return ;
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
