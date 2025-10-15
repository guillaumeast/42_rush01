#ifndef TYPES_H
# define TYPES_H

# include "rush01.h"

typedef struct s_args
{
	int		*values;	// Tableau d'entiers
	size_t	size;		// Taille de values
}	t_args;

typedef struct s_cell
{
	int		value;				// Valeur de la cellule (0 si inconnue)
	int		*possible_values;	// Tableau des valeurs possibles pour la cellule
	size_t	possible_size;		// Taille de possible_values (nombre de valeurs possibles pour la cellule)
}	t_cell;

typedef struct s_map
{
	t_cell	***content;	// Tableau de tableau de pointeurs vers des cellules (tableau à 2 dimensions)
	size_t	size;		// Taille de la map (size = longueur = largeur car map carrée)
}	t_map;

typedef struct s_run
{
	t_args	args;
	t_map	map;
}	t_run;

#endif