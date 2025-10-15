#ifndef CELL_H
# define CELL_H

#include "rush01.h"

t_cell	*new_cell(t_run *run, size_t y, size_t x, int value);
void	set_value(t_cell *cell, int value);
t_run	*remove_possibilitie(t_run *run, t_cell *cell, int possibilitie);
void	free_cell(t_cell *cell);

#endif