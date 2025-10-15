#ifndef PROPAGE_H
# define PROPAGE_H

#include "rush01.h"

t_run	*solve_cell(t_run *run, t_cell *cell, int value);
t_run	*solve(t_run *run);

#endif