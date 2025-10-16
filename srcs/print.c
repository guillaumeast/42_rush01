#include "rush01.h"

void	print_int_tab(int *tab, size_t size, int nl)
{
	size_t	i;
	char	c;

	write(1, "[", 1);
	i = 0;
	while (tab && i < size)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		if (i < size - 1)
			write(1, "|", 1);
		i++;
	}
	write(1, "]", 1);
	if (nl)
		write(1, "\n", 1);
}

void	print_args(t_args *args)
{
	char	c;

	write(1, "-----------ARGS----------\n", 26);
	c = ((int) args->map_size) + '0';
	write(1, "map_size = ", 11);
	write(1, &c, 1);
	write(1, "\n", 1);
	write(1, "colup    = ", 11);
	if (args->colup)
		print_int_tab(args->colup, args->map_size, 0);
	write(1, "\n", 1);
	write(1, "coldown  = ", 11);
	if (args->coldown)
		print_int_tab(args->coldown, args->map_size, 0);
	write(1, "\n", 1);
	write(1, "rowleft  = ", 11);
	if (args->rowleft)
		print_int_tab(args->rowleft, args->map_size, 0);
	write(1, "\n", 1);
	write(1, "rowright = ", 11);
	if (args->rowright)
		print_int_tab(args->rowright, args->map_size, 0);
	write(1, "\n", 1);
	write(1, "-------------------------\n", 26);
}
