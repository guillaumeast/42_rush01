#ifndef CHECK_H
# define CHECK_H

#include "rush01.h"

t_bool	check_colup(t_run *run, size_t col);
t_bool	check_coldown(t_run *run, size_t col);
t_bool	check_rowleft(t_run *run, size_t row);
t_bool	check_rowright(t_run *run, size_t row);

#endif
