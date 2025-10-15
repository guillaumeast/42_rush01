#include "rush01.h"

// Caller must free
t_cell	*new_cell(int value)
{
	t_cell	*cell;

	cell = malloc(sizeof(t_cell));
	if (!cell)
		return (NULL);
	set_cell(cell, value);
	return (cell);
}

void	set_cell(t_cell *cell, int value)
{
	if (value == 0)
	{
		cell->value = 0;
		cell->possible_1 = 1;
		cell->possible_2 = 1;
		cell->possible_3 = 1;
		cell->possible_4 = 1;
		cell->possible_count = 4;
	}
	else
	{
		cell->value = value;
		cell->possible_1 = 0;
		cell->possible_2 = 0;
		cell->possible_3 = 0;
		cell->possible_4 = 0;
		cell->possible_count = 0;
	}
}

void	remove_possibilitie(t_cell *cell, int possibilitie)
{
	if (possibilitie == 1)
		cell->possible_1 = 0;
	else if (possibilitie == 2)
		cell->possible_2 = 0;
	else if (possibilitie == 3)
		cell->possible_3 = 0;
	else if (possibilitie == 4)
		cell->possible_4 = 0;
	cell->possible_count--;
}
