#ifndef PRINT_H
# define PRINT_H

# include "rush01.h"

void	print_args(t_run *run);
void	print_int_tab(int *tab, size_t size, int nl);
void	print_cell(t_cell *cell);
void	print_map(t_run *run);
void	print_run(t_run *run);

#endif