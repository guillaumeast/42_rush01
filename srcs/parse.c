#include "rush01.h"

static int	**malloc_map(size_t size);
static void	populate_map(int *args, t_run *run);

t_run	*parse(int *args, size_t size, t_run *run)
{
	int	i;
	int	y;
	int	x;

	run->map_size = size / 4 + 2;
	run->map = malloc_map(run->map_size);
	if (!run->map)
		return (NULL);
	populate_map(args, run);

}

static int	**malloc_map(size_t size)
{
	int	**map;
	int	i;

	map = malloc((size) * sizeof(int *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = malloc((size) * sizeof(int));
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			return (NULL);
		}
		i++;
	}
	return (map);
}

static void	populate_map(int *args, t_run *run)
{
	int	i;
	int j;

	run->map[0][0] = 0;
	run->map[0][run->map_size - 1] = 0;
	run->map[run->map_size - 1][0] = 0;
	run->map[run->map_size - 1][run->map_size - 1] = 0;
	j = 0;
	i = 1;
	while(i < run->map_size - 1)
		run->map[0][i++] = args[j++];
	i = 1;
	while(i < run->map_size - 1)
		run->map[run->map_size - 1][i++] = args[j++];
	i = 1;
	while (i < run->map_size - 1)
		run->map[i++][0] = args[j++];
	i = 1;
	while(i < run->map_size - 1)
		run->map[i++][run->map_size - 1] = args[j++];
}


