#include "rush01.h"

void	print_map(t_run *run)
{
	size_t	i;
	size_t	j;

	if (!run)
		return ;
	else if (!run->map.content)
		write(2, "No map\n", 7);
	else
	{
		i = 0;
		while (i < run->map.size && run->map.content[i])
		{
			j = 0;
			while (j < run->map.size && run->map.content[i][j])
			{
				if (run->map.content[i][j]->value == 0)
					write (1, " ", 1);
				else
					ft_putnbr(run->map.content[i][j]->value);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}

void	print_args(t_run *run)
{
	size_t	i;

	if (!run)
		return ;
	else if (!run->args.values)
		write(2, "No args\n", 8);
	else
	{
		write(1, "args.size   = ", 14);
		ft_putnbr(run->args.size);
		write(1, "\n", 1);
		write(1, "args.values = ", 14);
		i = 0;
		while (i < run->args.size)
		{
			ft_putnbr(run->args.values[i]);
			i++;
		}
		write(1, "\n", 1);
	}
}

void	print_run(t_run *run)
{
	if (!run)
		write(2, "No run\n", 7);
	else
	{
		write(1, "------------------ RUN ------------------\n", 42);
		print_args(run);
		write(1, "-----------------------------------------\n", 42);
		print_map(run);
		write(1, "-----------------------------------------\n\n", 43);
	}
}
