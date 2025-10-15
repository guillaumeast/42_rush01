#ifndef CELL_H
# define CELL_H

#include "rush01.h"

t_cell	*new_cell(t_run **run, size_t y, size_t x, int value);
void	set_value(t_cell *cell, int value);
void	rm_choice(t_cell *cell, int choice);
void	free_cell(t_cell **cell);

#endif