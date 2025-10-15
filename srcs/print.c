#include "rush01.h"

void	print_int_tab(int *tab, size_t size, int nl)
{
	size_t	i;

	printf("[");
	i = 0;
	while (tab && i < size)
	{
		printf("%d", tab[i]);
		if (i < size - 1)
			printf("|");
		i++;
	}
	printf("]");
	if (nl)
		printf("\n");
}

void	print_args(t_run *run)
{
	if (!run)
		return ;
	else if (!run->args.values)
		printf("|-> No args\n");
	else
	{
		printf("|-> args = (%zu) ", run->args.size);
		print_int_tab(run->args.values, run->args.size, 1);
	}
}

void	print_cell(t_cell *cell)
{
	printf("------------CELL[%zu][%zu]------------\n", cell->y, cell->x);
	printf("|-> value = %d\n", cell->value);
	printf("|-> possibilities (%d) = ", cell->choices.sum);
	print_int_tab(cell->choices.tab, cell->choices.size, 1);
	printf("----------------------------------\n");
}

void	print_map(t_run *run)
{
	size_t	i;
	size_t	j;

	if (!run)
		return ;
	else if (!run->map.cells)
		printf("No map\n");
	else
	{
		i = 0;
		while (i < run->map.size && run->map.cells[i])
		{
			j = 0;
			while (j < run->map.size && run->map.cells[i][j])
			{
				if (run->map.cells[i][j]->value == 0)
					write (1, " ", 1);
				else
					ft_putnbr(run->map.cells[i][j]->value);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}

void	print_run(t_run *run)
{
	if (!run)
		write(2, "No run\n", 7);
	else
	{
		write(1, "\n------------------ RUN ------------------\n", 43);
		print_args(run);
		write(1, "-----------------------------------------\n", 42);
		print_map(run);
		write(1, "-----------------------------------------\n\n", 43);
	}
}
