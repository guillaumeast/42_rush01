#ifndef TYPES_H
# define TYPES_H

# include "rush01.h"

typedef struct s_args
{
	int		*values;
	size_t	size;
}	t_args;

typedef struct s_choices
{
	int		*tab;
	size_t	size;
	int		sum;
}	t_choices;

typedef struct s_cell
{
	size_t		y;
	size_t		x;
	int			value;
	t_choices	choices;
}	t_cell;

typedef struct s_map
{
	t_cell	***cells;	// Tableau de tableau de pointeurs vers des cellules (tableau à 2 dimensions)
	size_t	size;
}	t_map;

typedef struct s_run
{
	t_args	args;
	t_map	map;
}	t_run;

#endif