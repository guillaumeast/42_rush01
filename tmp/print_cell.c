#include "rush01.h"

static void	print_cell_value(t_cell *cell)
{
	char **res;

	res = malloc(5 * sizeof(char *));
	printf("┌───────┐\n");
	printf("│ ┌───┐ │\n");
	printf("│ │ %d │ │\n", cell->value);
	printf("│ └───┘ │\n");
	printf("└───────┘\n");
}

static void	print_cell_poss(t_run *run, t_cell *cell)
{
	// TODO: convert cell->possibilites into int[map.size - 2] with 1 (possible) or 0 (impossible)
	int		*possibilities = {1, 1, 1, 1};
	char 	*poss_chars;
	size_t	i;

	poss_chars = malloc(run->map.size - 2);
	if (!poss_chars)
		return ;
	i = 0;
	while (i < run->map.size - 2)
	{
		if (possibilities[i] == 1)
			poss_chars[i] = possibilities[i] + 1 + '0';
		else
			poss_chars[i] = ' ';
		i++;
	}
	printf("┌───────┐\n");
	printf("│ %d   %d │\n", poss_chars[0], poss_chars[1]);
	printf("│       │\n");
	printf("│ %d   %d │\n", poss_chars[2], poss_chars[3]);
	printf("└───────┘\n");
}

static char	*get_line_1(t_cell *cell)
{
	if (cell->value > 0)
		return "│ ┌───┐ │";
	else if (cell->choices.tab[0] == 1 && cell->choices.tab[1] == 1)
		return "│ 1   2 │";
	else if (cell->choices.tab[0] == 1 && cell->choices.tab[1] == 0)
		return "│ 1     │";
	else if (cell->choices.tab[0] == 0 && cell->choices.tab[1] == 0)
		return "│       │";
	else if (cell->choices.tab[0] == 0 && cell->choices.tab[1] == 1)
		return "│     2 │";
}

void	print_cell_sqr(t_run *run, t_cell *cell)
{
	char	*res[5];

	res[0] = "┌───────┐";
	res[1] = get_line_1(cell);
	res[2] = get_line_2(cell);
	res[3] = get_line_3(cell);
	res[4] = "└───────┘";

	if (cell->value == 0)
	{
		res[2] = "│       │";
		if (cell->choices.tab[2] == 1 && cell->choices.tab[3] == 1)
			res[3] = "│ 3   4 │";
		else if (cell->choices.tab[2] == 1 && cell->choices.tab[3] == 0)
			res[3] = "│ 3     │";
		else if (cell->choices.tab[2] == 0 && cell->choices.tab[3] == 0)
			res[3] = "│       │";
		else if (cell->choices.tab[2] == 0 && cell->choices.tab[3] == 1)
			res[3] = "│     4 │";
	}
	else
	{
		res[2] = strcat(strcat("│ │ ", cell->value), " │ │");
		res[3] = "│ └───┘ │";
	}
	return (res);
}
