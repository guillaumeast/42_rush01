#ifndef TYPES_H
# define TYPES_H

# include "rush01.h"

# define TRUE 1
# define FALSE 0
typedef char	t_bool;

# define MAP_SIZE_MIN 3
# define MAP_SIZE_MAX 9

typedef struct s_args
{
	int		*colup;
	int		*coldown;
	int		*rowleft;
	int		*rowright;
	size_t	map_size;
}	t_args;

typedef struct map
{
	int		**content;
	size_t	size;
	t_bool	is_complete;
}	t_map;


typedef struct s_run
{
	t_args	*args;
	t_map	*map;
}	t_run;

#endif
